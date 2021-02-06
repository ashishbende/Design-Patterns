package main

type iDepartment interface{
	execute(* patient)
	setNext(iDepartment)
}