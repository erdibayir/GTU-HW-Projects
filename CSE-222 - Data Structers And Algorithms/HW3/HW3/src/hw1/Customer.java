package hw1;

/**
 * Customer class for Customers.Extends person and implements ICustomer Interface.
 * @author Erdi Bayir
 * @since 10.04.2021
 */
public class Customer extends Person implements ICustomer{
    private String address;
    private String phone;
    private GTUHybridList<Furniture> orders = new GTUHybridList<>();
    public Customer(String name, String surname, String email, String password, int id) {
        super(name, surname, email, password, id);
    }

    /**
     * Default Constructor for create Customer.
     */
    public Customer() {
    }

    /**
     * Show Costumer Previously Orders.
     */
    public void showOrders(){
        System.out.println( "-----" + name + " " + surname +  " Orders -----");
        if(orders.size() <= 0 ){
            System.out.println("There is no orders!!!");
        }
       for (int i = 0 ; i < orders.size(); i++){
           System.out.println("---------------------------");
           System.out.println( i+1 + ".Order Information");
           Furniture tempFurniture = (Furniture) orders.get(i);
           System.out.println("Product Type : " + tempFurniture.getTypeProduct());
           System.out.println("Model Name : " + tempFurniture.getModelName());
           System.out.println("Color Name : " + tempFurniture.getColorName());
           System.out.println("Address : " + address);
           System.out.println("Phone Number : " + phone);
           System.out.println("---------------------------");
       }
    }

    /**
     * Getter of Order Array
     * @return Customer Orders
     */
    public GTUHybridList<Furniture> getOrders() {
        return orders;
    }

    /**
     * Show List of All Products in Company
     * @param company Company object
     */
    public void showListOfProduct(Company company){
        for (int i = 0; i < company.getBranches().size(); i ++ ){
            Branch temp = (Branch) company.getBranches().get(i);
            System.out.println("------------- " + temp.getBranchName() +" -------------");
            if(temp.getBranchEmployees().getSize() != 0) {
                BranchEmployee tempEmployee = (BranchEmployee) temp.getBranchEmployees().get(0);
                tempEmployee.showChairStock(temp);
                tempEmployee.showDeskStock(temp);
                tempEmployee.showMeetingTableStock(temp);
                tempEmployee.showOfficeCabinetStock(temp);
                tempEmployee.showBookCaseStock(temp);
            }
            else
                System.out.println(temp.getBranchName() + " Branch doesnt have any stock!");
        }

    }

    /**
     * Search Product in Company
     * @param company Company Class Object
     * @param searchObject search product by selected Customer
     */
    public void searchProduct(Company company,Furniture searchObject){
        int counter = 0;
        System.out.println("Branches with stock related to" +  " " + searchObject.typeProduct + " " + searchObject.getModelName() + "  product:");
        for (int i = 0 ; i < company.getBranches().size(); i++){
            Branch tempBranch = (Branch) company.getBranches().get(i);
            if (searchObject.getTypeProduct().equals("Chair")){
                if(searchProductHelper(tempBranch,tempBranch.getChairs(),searchObject)) {
                    counter++;
                    System.out.println(counter + "." + tempBranch.getBranchName() + " Branch");
                }
            }
            if (searchObject.getTypeProduct().equals("Desk")){
                if(searchProductHelper(tempBranch,tempBranch.getDesks(),searchObject)) {
                    counter++;
                    System.out.println(counter + "." + tempBranch.getBranchName() + " Branch");
                }
            }
            if (searchObject.getTypeProduct().equals("Meeting Table")){
                if(searchProductHelper(tempBranch,tempBranch.getMeetingTables(),searchObject)) {
                    counter++;
                    System.out.println(counter + "." + tempBranch.getBranchName() + " Branch");
                }
            }
            if (searchObject.getTypeProduct().equals("Office Cabinet")){
                if(searchProductHelper(tempBranch,tempBranch.getOfficeCabinet(),searchObject)) {
                    counter++;
                    System.out.println(counter + "." + tempBranch.getBranchName() + " Branch");
                }
            }
            if (searchObject.getTypeProduct().equals("Book Case")){
                if(searchProductHelper(tempBranch,tempBranch.getBookCases(),searchObject)) {
                    counter++;
                    System.out.println(counter + "." + tempBranch.getBranchName() + " Branch");
                }
            }
        }
    }

    /**
     * It is a helper method for searchProduct.
     * @param currentBranch current branch in company system
     * @param array generic array for all products
     * @param searchObject search product
     * @param <T> for generic method
     * @return true if searching is successfully done
     */
    public <T> boolean  searchProductHelper(Branch currentBranch,GTUHybridList<T> array,Furniture searchObject){
        for (int i = 0 ; i < array.size(); i ++){
            array.get(i).toString().equalsIgnoreCase(searchObject.toString());
            return true;
        }
        return false;
    }

    /**
     * Setter of orders
     * @param orders Customer orders
     */
    public void setOrders(GTUHybridList<Furniture> orders) {
        this.orders = orders;
    }

    /**
     * Getter of Adress
     * @return address of Customer
     */
    public String getAddress() {
        return address;
    }

    /**
     * Setter of Adress
     * @param address address of Customer
     */
    public void setAddress(String address) {
        this.address = address;
    }

    /**
     * Getter of phone number
     * @return phone number of Customer
     */
    public String getPhone() {
        return phone;
    }

    /**
     * Setter of phone number
     * @param phone phone number of Customer
     */
    public void setPhone(String phone) {
        this.phone = phone;
    }

    /**
     * Override of toString method
     * @return Email and password of Customer
     */
    @Override
    public String toString() {
        return " Email: " + email + " Password: " + password;
    }
}
