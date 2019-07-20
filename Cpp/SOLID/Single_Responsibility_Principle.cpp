#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

struct Journal{
	string m_title;
	vector<string> m_entries;
	
	Journal(const string& title)
		: m_title(title) {}
	
	void add_entry(const string& entry){
		static int count = 1;
		m_entries.push_back(to_string(count++) +":"+entry);
	}
	
	// we are adding additional responsibility for persisting 
	// the journal into a file. We need to have a separation of concerns

	void save(const string& filename ){
			ofstream ofs(filename);
			for(auto& e: m_entries){
					ofs << e << endl;
			}
	}
};

struct PersistenceManager{
	static void save(const Journal& j, const string& filename ){
			ofstream ofs(filename);
			for(auto& e: j.m_entries){
					ofs << e << endl;
			}
	}
};

int main(){
	Journal journal{"My Journal"};
	journal.add_entry("Today is Friday");
	journal.add_entry("I'm meeting a friend");
	
	
	// instead of asking journal to save information
	//journal.save("my_journal.txt");
	
	PersistenceManager pm;
	pm.save(journal, "my_journal.txt");
	return 0;
}
