package main

func main() {
	client := &client{}
	mac := &mac{}
	client.insertSquareUsbInComputer(mac)
	windowsMachine := &windows{}
	windowsAdapter := &windowsAdapter{
		windowsPC: windowsMachine,
	}
	client.insertSquareUsbInComputer(windowsAdapter)
}
