// dont create interfaces that are too large

#include <iostream>

struct Document;

/*
// this interface is doing too many things
struct IMachine {
  virtual void print(Document &doc) = 0;
  virtual void scan(Document &doc) = 0;
  virtual void fax(Document &doc) = 0;
};

// these are okay
struct MultiFunctionPrinter : IMachine {
  void print(Document &doc) override {}
  void scan(Document &doc) override {}
  void fax(Document &doc) override {}
};

struct Scanner : IMachine {
    // print fnc is not needed, sends wrong message
    void print(Document &doc) override {}
    void scan(Document &doc) override {}
    void fax(Document &doc) override {}
};
*/

struct IPrinter {
  virtual void print(Document &doc) = 0;
};

struct IScanner {
  virtual void scan(Document &doc) = 0;
};

struct IFax {
  virtual void fax(Document &doc) = 0;
};

struct Printer : IPrinter {
  void print(Document &doc) override {}
};

struct Scanner : IScanner {
  void scan(Document &doc) override {}
};

struct Fax : IFax {
  void fax(Document &doc) override {}
};

// to get more functionality, with abstract interface
struct IMachine : IPrinter, IScanner {};

// concrete IMachine implementation - decorator pattern
struct Machine : IMachine {
  IPrinter &printer;
  IScanner &scanner;

  Machine(IPrinter &printer, IScanner &scanner)
      : printer(printer), scanner(scanner) {}

  void print(Document &doc) override { printer.print(doc); }

  void scan(Document &doc) override { scanner.scan(doc); }
};

int main() {

  Scanner scanner;
  Printer printer;
  Machine mfm(printer, scanner);

  return 0;
}