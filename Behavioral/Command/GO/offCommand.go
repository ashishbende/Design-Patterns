package main

type offCommand struct {
	device iDevice
}

func (c *offCommand) execute() {
	c.device.off()
}
