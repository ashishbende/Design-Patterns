#include <iostream>
#include <memory>
using namespace std;

// responsible for prepraration of message
class ITextHander {
 public:
  virtual string prepareMessage(const string &text) const = 0;
  virtual ~ITextHander() = default;
};

// responsible for sharing mechanism of message
class ITextSharer {
 public:
  virtual ~ITextSharer() = default;

  explicit ITextSharer(const ITextHander &handler) : m_textHandler(handler) {}
  bool shareText(const string &text) {
    const string preparedText = m_textHandler.prepareMessage(text);
    return sharePreparedText(preparedText);
  }

 protected:
  virtual bool sharePreparedText(const string &preparedText) = 0;

 private:
  const ITextHander &m_textHandler;
};

class EncryptedTextHandler : public ITextHander {
 public:
  string prepareMessage(const string &text) const override {
    cout << "EncryptedTextHandler::prepareMessage() encrypting text... "
         << endl;
    string encrypted = xorEncrypted(text);
    return encrypted;
  }

 private:
  string xorEncrypted(const string &input) const {
    char key = 64;
    string output = input;
    for (int i = 0; i < input.size(); i++) {
      output[i] = input[i] ^ key;
    }
    return output;
  }
};

class EmailEncryptedShare : public ITextSharer {
 public:
  explicit EmailEncryptedShare(const EncryptedTextHandler &handler)
      : ITextSharer(handler) {}
  bool sharePreparedText(const string &text) override {
    cout << "EmailEncryptedShare::shareText() sharing text: " << text << endl;
    return true;
  }
};

class PlainTextHandler : public ITextHander {
 public:
  virtual string prepareMessage(const string &text) const override {
    cout << "PlainTextHandler::parepareMessage() returning original text .. "
         << endl;
    return text;
  }
};

class EmailShare : public ITextSharer {
 public:
  explicit EmailShare(const PlainTextHandler &handler) : ITextSharer(handler) {}
  bool sharePreparedText(const string &text) override {
    cout << "EmailShare::shareText() sharing text: " << text << endl;
    return true;
  }
};

int main() {
  PlainTextHandler pHandler = PlainTextHandler();
  EncryptedTextHandler eHandler = EncryptedTextHandler();

  const unique_ptr<ITextSharer> sharingServices[]{
      make_unique<EmailShare>(pHandler),
      make_unique<EmailEncryptedShare>(eHandler)};

  const string content = "Beam me up, Scotty!";
  for (const auto &service : sharingServices) {
    service->shareText(content);
    cout << endl;
  }
  return 0;
}