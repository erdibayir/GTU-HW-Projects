package hw1;

/**
 * Company Class For Furniture Company.
 *  Company Class have branches,admin and customers.
 * @author Erdi Bayir
 * @since 13.03.2021
 */
public class Company {
    protected String name;
    protected GTULinkedList<Branch> branches;
    protected Administrator admin;
    protected GTUArrayList<Customer> customers;

    /**
     * Constructor for create Company with name.
     * @param name name of company
     */
    public Company(String name) {
        this.name = name;
        branches = new GTULinkedList<Branch>();
        customers = new GTUArrayList<>();
        admin = new Administrator("Erdi","Bayır","erdi.bayir@gmail.com","erdi123",1);
        branches.add(new Branch("Ankara"));
        branches.add(new Branch("Istanbul"));
        branches.add(new Branch("Izmir"));
        branches.add(new Branch("Antalya"));
    }

    /**
     * Getter of company name
     * @return company name
     */
    public String getName() {
        return name;
    }

    /**
     * Setter of company name
     * @param name company name
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * Getter of Admin object
     * @return Admin
     */
    public Administrator getAdmin() {
        return admin;
    }

    /**
     * Getter of branches
     * @return branches
     */
    public GTULinkedList<Branch> getBranches() {
        return branches;
    }

    /**
     * Setter of branches
     * @param branches branch array
     */
    public void setBranches(GTULinkedList<Branch> branches) {
        this.branches = branches;
    }

    /**
     * Setter of Admin object
     * @param admin set admin
     */
    public void setAdmin(Administrator admin) {
        this.admin = admin;
    }

    /**
     * Getter of Customers array
     * @return customer array
     */
    public GTUArrayList<Customer> getCustomers() {
        return customers;
    }

    /**
     * Setter of Customer array
     * @param customers set customers
     */
    public void setCustomers(GTUArrayList<Customer> customers) {
        this.customers = customers;
    }
}