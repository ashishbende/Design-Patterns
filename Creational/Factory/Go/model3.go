package main

type model3 struct {
	car
}

func newModel3() iCar {
	return &model3{
		car: car{
			name:       "Model 3",
			motors:     2,
			driveRange: 310,
		},
	}
}
