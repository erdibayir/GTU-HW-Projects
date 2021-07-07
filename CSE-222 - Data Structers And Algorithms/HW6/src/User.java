import java.util.Random;

/**
 * @author Erdi Bayır
 * @since 26-05-2021
 * User Class Implementation.
 */
public class User {
    private String id;
    private String password;
    private String name;

    /**
     * User 3 parameter constructor to create User object
     * @param id id of user
     * @param name name of user
     * @param password password of user
     */
    public User(String id, String name, String password) {
        this.id = id;
        this.password = password;
        this.name = name;
    }

    /**
     * User 2 parameter constructor to create User object
     * @param name name of user
     * @param password password of user
     */
    public User(String name, String password) {
        GenerateId(8);
        this.password = password;
        this.name = name;
    }

    /**
     * Return Id of user
     * @return Return Id
     */
    public String getId() {
        return id;
    }
    /**
     * Return password of user
     * @return Return password
     */
    public String getPassword() {
        return password;
    }

    /**
     * Return name of user
     * @return Return name
     */
    public String getName() {
        return name;
    }

    /**
     * Set name of user
     * @param name new name value
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * Set password of user
     * @param password new password value
     */
    public void setPassword(String password) {
        this.password = password;
    }

    /**
     * It generate unique user id
     * @param length length of id
     */
    public void GenerateId(int length) {
        this.id = String.valueOf(length < 1 ? 0 : new Random()
                .nextInt((9 * (int) Math.pow(10, length - 1)) - 1)
                + (int) Math.pow(10, length - 1));
    }
}
