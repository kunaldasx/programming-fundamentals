import java.util.*;  
class NewException extends Exception{  
    int x;  
    NewException(int y) {  
        x=y;  
    }  
    public String toString(){  
        return ("Exception value =  "+x) ;  
    }  
}  
class UserDefinedExcep{  
    public static void main(String args[]){  
        try{  
            throw new NewException(5);
        }  
        catch(NewException ex){  
            System.out.println(ex) ;  
        }  
    }  
}  