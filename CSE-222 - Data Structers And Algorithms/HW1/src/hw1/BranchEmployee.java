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
    public <T> MyArray<T> addFurniture(MyArray<T> furnitures, T newFurniture){
        furnitures.add(newFurniture);
        return furnitures;
    }

    /**
     * Add Furniture To Company System.
     * @param furnitures takes furniture array
     * @param deleteFurniture takes new furniture for add to system
     * @return new furniture array
     */
    public <T> MyArray<T> removeFurniture(MyArray<T> furnitures, T deleteFurniture){
        furnitures.delete(deleteFurniture);
        return furnitures;
    }

    /**
     * Show Stock of Chairs  In System.
     * @param ownBranch takes branch object of current employee for show products
     */
    public void showChairStock(Branch ownBranch){
        System.out.println("    (Chairs)");
        if (ownBranch.getChairs().getSize() == 0){
            System.out.println("No chair in stock!!");
        }
        else {
            for (int i = 0; i < ownBranch.getChairs().getSize(); i++) {
                Chair tempChair = (Chair) ownBranch.getChairs().getArrayElement(i);
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
        if (ownBranch.getDesks().getSize() == 0){
            System.out.println("No desk in stock!!");
        }
        else {
            for (int i = 0; i < ownBranch.getDesks().getSize(); i++) {
                Desk tempDesk = (Desk) ownBranch.getDesks().getArrayElement(i);
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
        if (ownBranch.getMeetingTables().getSize() == 0){
            System.out.println("No meeting table in stock!!");
        }
        else {
            for (int i = 0; i < ownBranch.getMeetingTables().getSize(); i++) {
                MeetingTable tempTable = (MeetingTable) ownBranch.getMeetingTables().getArrayElement(i);
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
        if (ownBranch.getOfficeCabinet().getSize() == 0){
            System.out.println("No office cabinet in stock!!");
        }
        else {
            for (int i = 0; i < ownBranch.getOfficeCabinet().getSize(); i++) {
                OfficeCabinet tempCabinet = (OfficeCabinet) ownBranch.getOfficeCabinet().getArrayElement(i);
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
        if (ownBranch.getBookCases().getSize() == 0){
            System.out.println("No book case in stock!!");
        }
        else {
            for (int i = 0; i < ownBranch.getBookCases().getSize(); i++) {
                BookCase tempCase = (BookCase) ownBranch.getBookCases().getArrayElement(i);
                System.out.println(i + 1 + ".Book Case -> " + tempCase.getModelName());
            }
        }
    }
    /**
     * Show Employee id,name,surname,email and password.
     */
    public void accessCustomerOrder(MyArray<Customer> customer,int selectedCustomer){
            Customer temp = (Customer) customer.getArrayElement(selectedCustomer-1);
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
