// Java program to implement the use of the different access modifiers.
class Account {
    String name;
    public String email;
    protected float balance;
    private String password;

    // getters & setters
    private void setPassword(String pass) {
        this.password = pass;
    }

    public String getPassword() {
        setPassword("kunal@123");
        return this.password;
    }
}

public class Access_Modifiers {
    public static void main(String args[]) {
        Account account = new Account();
        account.name = "Kunal";
        account.email = "kunaldas0361@gmail.com";
        account.balance = 700000;
        // account.password
        // This can't be accessed as it is private.
        // So we use getters & setters

        // account.setPassword("abcd"); -> Now this can't be called because it is
        // private
        System.out.println(account.getPassword());
    }
}