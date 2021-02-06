package main

import "fmt"

type securityCode struct{
	code int
}

func newSecurityCode(code int) *securityCode{
	return &securityCode{
		code: code,
	}
}

func (s *securityCode)checkCode(inputCode int) error{
	if (s.code != inputCode){
		return fmt.Errorf("Security code invalid.")
	}
	fmt.Println("Security code verified!")
	return nil
}