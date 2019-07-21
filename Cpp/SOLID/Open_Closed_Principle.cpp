#include<iostream>
#include<string>
#include<vector>
#include<functional>

using namespace std;

enum class Color { red, green, blue};
enum class Size { small, medium, large};

struct Product{
	string name;
	Color color;
	Size size; 
};


struct ProductFilter{
	vector<Product*> by_color(vector<Product*> items, Color color){
		vector<Product*> result;
		
		for(auto& i : items){
			if(i->color == color)
				result.push_back(i);
		}
		
		return result;
	}
	
	vector<Product*> by_size(vector<Product*> items, Size size){
		vector<Product*> result;
		
		for(auto& i : items){
			if(i->size == size)
				result.push_back(i);
		}
		
		return result;
	}
};


template <typename T> 
struct Specification{
	virtual bool is_satisfied(T* item)=0;
	/*AndSpecification<T> operator&&(Specification<T> && other){
		return AndSpecification<T>(*this, other);
	}*/
};

template <typename T>
struct Filter{
	virtual vector<T*> filter(vector<T*> items, 
					Specification<T>& spec)=0;
};

struct BetterFilter: Filter<Product>
{
		vector<Product*> filter(vector<Product*> items, Specification<Product>& spec) override{
			vector<Product*> result;			
			for(auto& i : items){
				if(spec.is_satisfied(i))
					result.push_back(i);
			}
			return result;		
		} 
}; 


struct ColorSpecification : Specification<Product>{
	Color m_color;
	
	ColorSpecification(Color color)
		: m_color(color){}
		
	bool is_satisfied(Product* item){
		if(item->color == m_color) return true;
		return false;
	}
};


struct SizeSpecification : Specification<Product>{
	Size m_size;
	
	SizeSpecification(Size size)
		: m_size(size){}
		
	bool is_satisfied(Product* item){
		return item->size == m_size;
	}
};


// a combinator specification
template<typename T>
struct AndSpecification : Specification<T>{
	Specification<T>& m_first;
	Specification<T>& m_second;
	
	AndSpecification(Specification<T>& first, Specification<T>& second)
		: m_first(first), m_second(second){}
	
	bool is_satisfied(T * item) override{
		return m_first.is_satisfied(item) && m_second.is_satisfied(item);
	}
};

int main(){ 
	Product apple{"Apple", Color::red, Size::small};
	Product tree{"Tree", Color::green, Size::large};
	Product house{"house", Color::blue, Size::large};
	 
	vector<Product*> items {&apple, &tree, &house};
	// not a good design
	//ProductFilter pf;
	//auto green_things = pf.by_color(items, Color::green);
	
	BetterFilter bf;
	ColorSpecification greenSpec(Color::green);
	
	auto green_things =  bf.filter(items, greenSpec); 
	
	for(auto& i : green_things){
		cout << i->name << " is green color." <<endl; 
	}
	
	
	
	SizeSpecification largeSpec(Size::large);
	
	auto large_things =  bf.filter(items, largeSpec);
	
	for(auto& i : large_things){
		cout << i->name << " is large in size." <<endl; 
	}
	
	
	//AndSpecification<Product> green_and_large_spec = greenSpec && largeSpec;
	AndSpecification<Product> green_and_large_spec(greenSpec, largeSpec);

	for(auto& i : bf.filter(items, green_and_large_spec)){
		cout << i->name << " is green and large in size." <<endl; 
	}
	
	return 0;
}
