package main

type modelS struct {
	car
}

func newModelS() iCar {
	return &modelS{
		car: car{
			name:       "Model S",
			motors:     2,
			driveRange: 402,
		},
	}
}
