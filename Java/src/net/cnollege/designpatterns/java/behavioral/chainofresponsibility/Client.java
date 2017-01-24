package net.cnollege.designpatterns.java.behavioral.chainofresponsibility;

public class Client{

    public static void main(String[] args) {
        Handler h1 = new ConcreteHandler1();
        Handler h2 = new ConcreteHandler2();
        Handler h3 = new ConcreteHandler3();

        h1.setSuccessor(h2);
        h2.setSuccessor(h3);

        System.out.println("..sending request R2");
        h1.handleRequest("R2");


        System.out.println("..sending request R2");
        h1.handleRequest("R1");


        System.out.println("..sending request R2");
        h1.handleRequest("R3");

        System.out.println("..sending request R2");
        h1.handleRequest("RX");


    }
}