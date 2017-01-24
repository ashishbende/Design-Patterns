package net.cnollege.designpatterns.java.behavioral.chainofresponsibility;

public class ConcreteHandler3 implements Handler{
    private Handler successor = null;

    public void handleRequest(String request){
        System.out.println(" R3 recevied the request....Can it handle?");
        if(request.equalsIgnoreCase("R3")){
            System.out.println(this.getClass().getName()+" => This one is mine!");
        }else{
            System.out.println(" Nah... I can't handle it! Sending it to next ");
            if(successor!=null){
                successor.handleRequest(request);
            }
        }
    }
    public void setSuccessor(Handler next){
        this.successor = next;
    }
}