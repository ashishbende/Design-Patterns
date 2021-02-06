package main

// product interface
type iCar interface {
	setName(name string)
	getName() string
	setMotors(motors int)
	getMotors() int
	setDriveRange(miles int)
	getDriveRange() int
}
