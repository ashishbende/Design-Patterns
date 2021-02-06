package main

import "fmt"

func main(){
	normalBuilder := getBuilder("normal")
	iglooBuilder := getBuilder("igloo")

	director := newDirector(normalBuilder)
	normalHouse := director.buildHouse()

	printHouseDetails(normalHouse)

	director = newDirector(iglooBuilder)
	igloo := director.buildHouse()
	printHouseDetails(igloo)
}

func printHouseDetails(h house){
	fmt.Println("--- house details ---")
	fmt.Printf(" house door type: %s",h.doorType)
	fmt.Printf(" house window type: %s",h.windowType)
	fmt.Printf(" house floors: %d",h.floor)
}
