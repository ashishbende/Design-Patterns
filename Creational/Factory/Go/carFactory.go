package main

import "fmt"

func getCar(carModel string) (iCar, error) {
	if carModel == "model3" {
		return newModel3(), nil
	}
	if carModel == "modelS" {
		return newModelS(), nil
	}
	return nil, fmt.Errorf("Cannot process given car type.")
}
