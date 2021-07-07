package hw1;

/**
 * Person Class keeps name,surname,email,id and password of persons
 * @author Erdi Bayır
 * @since 10.04.2021
 */
public class Person {
    protected String name;
    protected String surname;
    protected String email;
    protected String password;
    protected int id;

    /**
     * Constructor of Person class,it have parameters for create Person  with name,surname,email,password and id
     * @param name  takes name of Person
     * @param surname takes surname of Person
     * @param email takes email of Person
     * @param password takes password of Person
     * @param id  takes id of Person
     */
    public Person(String name, String surname, String email, String password,int id){
        this.name = name;
        this.surname = surname;
        this.email = email;
        this.password = password;
        this.id = id;
    }

    /**
     * Default Constructor
     */
    public Person() {
    }

    /**
     * Getter of Person Name.
     * @return Person Name
     */
    public String getName() {
        return name;
    }

    /**
     * Getter of Person Email.
     * @return Person Email
     */
    public String getEmail() {
        return email;
    }

    /**
     * Getter of Person Password
     * @return Person Password
     */
    public String getPassword() {
        return password;
    }
    /**
     * Getter of Person Id
     * @return Person Id
     */
    public int getId() {
        return id;
    }
    /**
     * Getter of Person Surname
     * @return Person Surname
     */
    public String getSurname() {
        return surname;
    }

    /**
     * Setter of Person Name
     * @param name Person name
     */
    public void setName(String name){
        this.name = name;
    }

    /**
     * Setter of Person Name
     * @param surname Person name
     */
    public void setSurname(String surname){
        this.surname = surname;
    }

    /**
     * Setter of Person Name
     * @param email Person name
     */
    public void setEmail(String email){
        this.email = email;
    }

    /**
     * Setter of Person Name
     * @param password Person name
     */
    public void setPassword(String password){
        this.password = password;
    }

    /**
     * Setter of Person Name
     * @param id Person name
     */
    public void setId(int id) {
        this.id = id;
    }

    /**
     * Override of toString method
     * @return Return Person Information
     */
    @Override
    public String toString(){
        return " Email: " + email + " Password: " + password;
    }

}
