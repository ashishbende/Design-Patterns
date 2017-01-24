public class MenuItem implements Invoker{
    private Command theCommand;

    public void setTheCommand(Command command){
        theCommand = cmd;
    }

    public void invoke(){
        theCommand.execute();
    }
}