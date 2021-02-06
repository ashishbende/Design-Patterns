/* A class should have a single reason to change.
 * */
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct Journal{
  string title;
  vector<string> entries;
  Journal(const string &title) : title(title) {}
  void add_entry(const string& entry) {
    static int count = 1;
    entries.push_back(to_string(count++)+":"+entry);
  }

  // here we are breaking single responsibility principle
  void save(const string& filename){
    ofstream  ofs(filename);
    for(auto& item: entries){
      ofs << item <<endl;
    }
    ofs.close();
  }
};

// keeping the separation of concern
// persistence manager should be responsible to save the journals
struct PersistenceManager{
  static void save(const Journal& j, const string& filename){
    ofstream  ofs(filename);
    for(auto& item: j.entries){
      ofs << item <<endl;
    }
    ofs.close();
  }
};

int main() {
  // create journal
  Journal myJournal{"Diary"};
  // add entries
  myJournal.add_entry("Today is Wednesday.");
  myJournal.add_entry("It is good day to implement SOLID principle.");

  PersistenceManager pm;
  pm.save(myJournal, "myJournal.txt");

  return 0;
}
