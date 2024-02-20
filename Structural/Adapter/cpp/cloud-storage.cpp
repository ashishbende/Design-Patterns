#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <memory>

using namespace std;

class CloudStorage {
 public:
  virtual bool uploadContent(const string& uploadContent) = 0;
  virtual int getFreeSpace() = 0;
  virtual ~CloudStorage() = default;
};

class CloudDrive : public CloudStorage {
 public:
  bool uploadContent(const string& content) override {
    cout << "Uploading " << content.length() << " bytes to CloudDrive:" << endl;
    return true;
  }

  int getFreeSpace() override {
    const int size = arc4random_uniform(20);
    cout << "Available CloudDrive storage : " << size << "GB" << endl;
    return size;
  }
};

class FastDrive : public CloudStorage {
 public:
  bool uploadContent(const string& content) override {
    cout << "Uploading " << content.length() << " bytes to FastDrive:" << endl;
    return true;
  }

  int getFreeSpace() override {
    const int size = arc4random_uniform(10);
    cout << "Available FastDrive storage : " << size << "GB" << endl;
    return size;
  }
};

class VirtualDrive {
 public:
  bool uploadData(const string& data, const int uniqueID) {
    cout << "Uploading to VirtualDrive : \"" << data << "\" ID: " << uniqueID
         << endl;
    return true;
  }
  int usedSpace() { return arc4random_uniform(10); }
  const int totalSpace = 15;
};

class VirtualDriveAdapter : public CloudStorage, private VirtualDrive {
 public:
  virtual bool uploadContent(const string& content) override {
    int uniqueID = generateUID();
    cout << "VirtualDriveAdapater::uploadContent() -> calling "
            "VirtualDrive:uploadData()"
         << endl;
    return uploadData(content, uniqueID);
  }

  virtual int getFreeSpace() override {
    cout << "VirtualDriveAdapter::getFreeSpace() -> Calling "
            "VirtualDrive::getAvailableStorage()"
         << endl;
    const int available = totalSpace - usedSpace();
    cout << "Available VirtualDrive storage: " << available << "GB" << endl;
    return available;
  }

 private:
  int generateUID() {
    const time_t result = time(nullptr);
    return result;
  }
};

int main() {
  const unique_ptr<CloudStorage> cloudServices[]{
      make_unique<CloudDrive>(), make_unique<FastDrive>(),
      make_unique<VirtualDriveAdapter>()};

  const string content = "Beam me up, Scotty!";
  for (const auto& service : cloudServices) {
    service->uploadContent(content);
    service->getFreeSpace();
    cout << endl;
  }
  return 0;
}