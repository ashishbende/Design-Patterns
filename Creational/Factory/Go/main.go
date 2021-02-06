package main

// replace direct object creation call by factory methods
import "fmt"

func main() {
	m3, _ := getCar("model3")
	mS, _ := getCar("modelS")

	printDetails(m3)
	printDetails(mS)
}

func printDetails(c iCar) {
	fmt.Printf("\nCar: %s", c.getName())
	fmt.Printf(", Drive Range: %d\n", c.getDriveRange())
	fmt.Printf(", Motors: %d\n", c.getMotors())
}
