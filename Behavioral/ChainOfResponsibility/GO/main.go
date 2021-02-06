package main

func main() {
	cashier := &cashier{}
	medical := &medical{}
	medical.setNext(cashier)

	doctor := &doctor{}
	doctor.setNext(medical)

	reception := &reception{}
	reception.setNext(doctor)

	patient := &patient{name: "Jimmy"}

	reception.execute(patient)
}
