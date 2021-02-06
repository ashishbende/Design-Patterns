package main

type onCommand struct {
	device iDevice
}

func (c *onCommand) execute() {
	c.device.on()
}
