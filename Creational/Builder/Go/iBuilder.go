package main
// builder interface
type iBuilder interface{
	setWindowType()
	setDoorType()
	setNumFloor()
	// build method
	getHouse() house
}

func getBuilder(builderType string) iBuilder{
	if builderType == "normal"{
		return &normalBuilder{}
	}

	if builderType == "igloo"{
		return &iglooBuilder{}
	}
	return nil
}