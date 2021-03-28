package hw1;

/**
 * Company Class For Furniture Company.
 *  Company Class have branches,admin and customers.
 * @author Erdi Bayir
 * @since 13.03.2021
 */
public class Company {
    protected String name;
    protected MyArray<Branch> branches;
    protected Administrator admin;
    protected MyArray<Customer> customers;

    /**
     * Constructor for create Company with name.
     * @param name name of company
     */
    public Company(String name) {
        this.name = name;
        branches = new MyArray<Branch>();
        customers = new MyArray<Customer>();
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
    public MyArray<Branch> getBranches() {
        return branches;
    }

    /**
     * Setter of branches
     * @param branches branch array
     */
    public void setBranches(MyArray<Branch> branches) {
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
    public MyArray<Customer> getCustomers() {
        return customers;
    }

    /**
     * Setter of Customer array
     * @param customers set customers
     */
    public void setCustomers(MyArray<Customer> customers) {
        this.customers = customers;
    }
}