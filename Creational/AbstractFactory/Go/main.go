package main

import (
	"fmt"
)

func main() {
	// distinctly define interfaces for each family type
	adidasFactory, _ := getSportsFactory("Adidas")
	adidasShoe := adidasFactory.makeShoe()
	adidasShort := adidasFactory.makeShort()

	printShoeDetails(adidasShoe)
	printShortDetails(adidasShort)

	nikeFactory, _ := getSportsFactory("Nike")
	nikeShoe := nikeFactory.makeShoe()
	printShoeDetails(nikeShoe)
	nikeShort := nikeFactory.makeShort()
	printShortDetails(nikeShort)
}

func printShoeDetails(s iShoe) {
	fmt.Println("--- shoe details ---")
	fmt.Printf("Logo : %s \n", s.getLogo())
	fmt.Printf("Size : %d \n", s.getSize())
}

func printShortDetails(s iShort) {
	fmt.Println("--- short details ---")
	fmt.Printf("Logo : %s \n", s.getLogo())
	fmt.Printf("Size : %d \n", s.getSize())
}
