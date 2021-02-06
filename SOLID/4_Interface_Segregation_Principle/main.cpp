/* Avoid creating interfaces that are too large.
 *  Break them
 * */

#include <iostream>

struct Document;

// this interface is trying to do too many things
struct IMachine{
  virtual void print(Document& doc) = 0;
  virtual void scan(Document& doc) = 0;
  virtual void fax(Document& doc) = 0;
};

// multi-function printer
struct MFP : IMachine{
  void print(Document &doc) override {
    // ok to do
  }
  void scan(Document &doc) override {
    // ok to do
  }
  void fax(Document &doc) override {
    // ok to do
  }
};

// problem if we need just the printer or scanner or fax machine
struct Scanner1 : IMachine{
  void print(Document &doc) override {
    // can't print
  }
  void scan(Document &doc) override {
    // ok to do
  }
  void fax(Document &doc) override {
    // can't fax
  }
};

/// Better solution would be segregate interfaces
struct IPrinter{
  virtual void print(Document& doc)=0;
};

struct IScanner{
  virtual void scan(Document& doc)=0;
};

struct IFax{
  virtual void fax(Document& doc) =0;
};

struct IMachine2 : IPrinter, IScanner{

};
struct Machine: IMachine2{
  // can use a decorator pattern
  // using references of IPrinter, IScanner type
  IPrinter& printer;
  IScanner& scanner;
  Machine(IPrinter &printer, IScanner &scanner) : printer(printer), scanner(scanner) {}

  void print(Document &doc) override {
    printer.print(doc);
  }
  void scan(Document &doc) override {
    scanner.scan(doc);
  }
};
struct Printer: IPrinter{
  void print(Document &doc) override {

  }
};

struct Scanner : IScanner{
  void scan(Document &doc) override {

  }
};
int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
