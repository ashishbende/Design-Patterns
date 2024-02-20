#include <iostream>
using namespace std;

class ITextShare {
 public:
  virtual bool shareText(const string& text) = 0;
  virtual ~ITextShare() = default;
};

class EmailShare : public ITextShare {
 public:
  bool shareText(const string& text) override {
    cout << "EmailShare::shareText() sharing text : " << text << endl;
    return true;
  }
};

class SMSShare : public ITextShare {
 public:
  bool shareText(const string& text) override {
    cout << "SMSShare::shareText() sharing text : " << text << endl;
    return true;
  }
};

class EmailShareEncrypted : public EmailShare {
 public:
  bool shareText(const string& text) override {
    cout << "EmailShareEncrypted::shareText() sharing text ... " << endl;
    string encrypted = xorEncrypted(text);
    return EmailShare::shareText(encrypted);
  }

 private:
  string xorEncrypted(const string& text) {
    char key = 64;
    string output = text;
    for (int i = 0; i < text.size(); i++) {
      output[i] = text[i] ^ key;
    }
    return output;
  }
};

class SMSShareEncrypted : public SMSShare {
 public:
  bool shareText(const string& text) override {
    cout << "SMSShareEncrypted::shareText() sharing text ... " << endl;
    string encrypted = xorEncrypted(text);
    return SMSShare::shareText(encrypted);
  }

 private:
  string xorEncrypted(const string& text) {
    char key = 64;
    string output = text;
    for (int i = 0; i < text.size(); i++) {
      output[i] = text[i] ^ key;
    }
    return output;
  }
};

// Design is becoming unmanageable with new features addition

class EmailShareAutoExpiring : public EmailShare {};

class SMSShareAutoExpiring : public SMSShare {};