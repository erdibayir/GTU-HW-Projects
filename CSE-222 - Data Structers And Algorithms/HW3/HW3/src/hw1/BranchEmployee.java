package hw1;
/**
 * BranchEmployee Class keeps name,surname,email,id and password of Branch Employees.
 * Employees can add and remove furniture to system.
 * Employees can show stock of products.
 * @author Erdi Bayir
 * @since 10.04.2021
 */
public class BranchEmployee extends Person implements IBranchEmployee{
    private Branch ownBranch;
    /**
     * Constructor of BranchEmployee class,it have parameters for create Employee with name,surname,email,password and id
     * @param name  takes name of Person
     * @param surname takes surname of Person
     * @param email takes email of Person
     * @param password takes password of Person
     * @param id  takes id of Person
     */
    public BranchEmployee(String name, String surname, String email, String password,int id) {
        super(name, surname, email, password,id);
    }
    /**
     * Default Constructor
     */
    public BranchEmployee() {
        super();
    }

    /**
     * Add Furniture To Company System.
     * @param furnitures takes furniture array
     * @param newFurniture takes new furniture for add to system
     * @return new furniture array
     */
    public <T> GTUHybridList<T> addFurniture(GTUHybridList<T> furnitures, T newFurniture){
        furnitures.add(newFurniture);
        return furnitures;
    }

    /**
     * Add Furniture To Company System.
     * @param furnitures takes furniture array
     * @param deleteFurniture takes new furniture for add to system
     * @return new furniture array
     */
    public <T> GTUHybridList<T> removeFurniture(GTUHybridList<T> furnitures, T deleteFurniture){
        furnitures.remove(deleteFurniture);
        return furnitures;
    }

    /**
     * Show Stock of Chairs  In System.
     * @param ownBranch takes branch object of current employee for show products
     */
    public void showChairStock(Branch ownBranch){
        System.out.println("    (Chairs)");
        if (ownBranch.getChairs().size() == 0){
            System.out.println("No chair in stock!!");
        }
        else {
            for (int i = 0; i < ownBranch.getChairs().size(); i++) {
                Chair tempChair = (Chair) ownBranch.getChairs().get(i);
                System.out.println(i + 1 + ".Chair -> " + tempChair.getModelName() + " - " + tempChair.getColorName());
            }
        }
    }
    /**
     * Show Stock of Desk  In System.
     * @param ownBranch takes branch object of current employee for show products
     */
    public void showDeskStock(Branch ownBranch){
        System.out.println("    (Desks)");
        if (ownBranch.getDesks().size() == 0){
            System.out.println("No desk in stock!!");
        }
        else {
            for (int i = 0; i < ownBranch.getDesks().size(); i++) {
                Desk tempDesk = (Desk) ownBranch.getDesks().get(i);
                System.out.println(i + 1 + ".Desk -> " + tempDesk.getModelName() + " - " + tempDesk.getColorName());
            }
        }
    }
    /**
     * Show Stock of Meeting Table In System.
     * @param ownBranch takes branch object of current employee for show products
     */
    public void showMeetingTableStock(Branch ownBranch){
        System.out.println("    (Meeting Tables)");
        if (ownBranch.getMeetingTables().size() == 0){
            System.out.println("No meeting table in stock!!");
        }
        else {
            for (int i = 0; i < ownBranch.getMeetingTables().size(); i++) {
                MeetingTable tempTable = (MeetingTable) ownBranch.getMeetingTables().get(i);
                System.out.println(i + 1 + ".Meeting Table -> " + tempTable.getModelName() + " - " + tempTable.getColorName());
            }
        }
    }
    /**
     * Show Stock of Office Cabinet In System.
     * @param ownBranch takes branch object of current employee for show products
     */
    public void showOfficeCabinetStock(Branch ownBranch){
        System.out.println("    (Office Cabinets)");
        if (ownBranch.getOfficeCabinet().size() == 0){
            System.out.println("No office cabinet in stock!!");
        }
        else {
            for (int i = 0; i < ownBranch.getOfficeCabinet().size(); i++) {
                OfficeCabinet tempCabinet = (OfficeCabinet) ownBranch.getOfficeCabinet().get(i);
                System.out.println(i + 1 + ".Office Cabinet -> " + tempCabinet.getModelName());
            }
        }
    }
    /**
     * Show Stock of Book Case In System.
     * @param ownBranch takes branch object of current employee for show products
     */
    public void showBookCaseStock(Branch ownBranch){
        System.out.println("    (Book Cases)");
        if (ownBranch.getBookCases().size() == 0){
            System.out.println("No book case in stock!!");
        }
        else {
            for (int i = 0; i < ownBranch.getBookCases().size(); i++) {
                BookCase tempCase = (BookCase) ownBranch.getBookCases().get(i);
                System.out.println(i + 1 + ".Book Case -> " + tempCase.getModelName());
            }
        }
    }
    /**
     * Show Employee id,name,surname,email and password.
     */
    public void accessCustomerOrder(GTUArrayList<Customer> customer,int selectedCustomer){
            Customer temp = (Customer) customer.get(selectedCustomer - 1);
            temp.showOrders();
    }

    /**
     * Show Employee Information.
     */
    public void showEmployeeInfo() {
        System.out.println("Employee -> Name: " + name + " Surname: " + surname + " Email: " + email + " Password: " + password);
    }

    /**
     * Getter of own branch of employee
     * @return own branch
     */
    public Branch getOwnBranch() {
        return ownBranch;
    }

    /**
     * Setter of own branch of employee
     * @param ownBranch own branch
     */
    public void setOwnBranch(Branch ownBranch) {
        this.ownBranch = ownBranch;
    }

    /**
     * * Override of toString method.
     * @return Branch Employee information
     */
    @Override
    public String toString(){
        return " Email: " + email + " Password: " + password;
    }
}
