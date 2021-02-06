package main

import "fmt"

type iSportsFactory interface{
	makeShoe() iShoe
	makeShort() iShort
}


func getSportsFactory(brand string) (iSportsFactory, error){
	if brand == "Adidas"{
		return &adidas{}, nil
	}
	if brand == "Nike"{
		return &nike{}, nil
	}
	return nil, fmt.Errorf("Wrong brand type provided.")
}

