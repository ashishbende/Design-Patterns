package main

// the concrete product struct
type car struct {
	name       string
	motors     int
	driveRange int
}

func (c *car) setMotors(motors int) {
	c.motors = motors
}

func (c *car) getMotors() int {
	return c.motors
}

func (c *car) setName(name string) {
	c.name = name
}

func (c *car) getName() string {
	return c.name
}

func (c *car) setDriveRange(miles int) {
	c.driveRange = miles
}

func (c *car) getDriveRange() int {
	return c.driveRange
}
