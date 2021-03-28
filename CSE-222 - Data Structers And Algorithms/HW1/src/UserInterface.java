import hw1.*;
import java.util.InputMismatchException;
import java.util.Scanner;
import java.io.IOException;

/**
 * UserInterface for test functions.It is a driver function.
 */
public class UserInterface {
    public static void main(String[] args) throws IOException {
        Company company = new Company("Amazon");
        menu(company);
    }

    /**
     * Main Interactive Menu For Furniture Company System and has different menus for operations.
     * @param company Company Class Object.
     */
    public static void menu(Company company) {
        int choice = -1;
        while (choice != 0) {
            System.out.println("---------------------------------------");
            System.out.println("Welcome " + company.getName() + " Furniture Store System");
            System.out.println("1 - Login As Administrator");
            System.out.println("2 - Login As Brach Employee");
            System.out.println("3 - Subscribe To The System As  Customer");
            System.out.println("4 - Login As Customer");
            System.out.println("0 - Exit");
            choice = takeInput(choice, 0, 4);
            switch (choice) {
                case 1:
                    adminMenu(company);
                    break;
                case 2:
                    employeeMenu(company);
                    break;
                case 3:
                    registerMenu(company);
                    break;
                case 4:
                    customerMenu(company);
                    break;
            }
        }
    }

    /**
     * Customer menu has Customer operations.Such as shop online,view order,see list of products.
     * @param company Company Class Object.
     */
    public static void customerMenu(Company company) {
        int choice = -1;
        String email, password;
        Scanner readString = new Scanner(System.in);
        System.out.println("Enter Email:");
        email = readString.next();
        System.out.println("Enter Your Password:");
        password = readString.next();
        //Login Test Functions
        Customer activeCustomer = new Customer("temp", "temp", email, password, -1);
        activeCustomer = searchCustomer(company, activeCustomer);
        if (activeCustomer != null) {
            while (choice != 0) {
                System.out.println("---------------------------------------");
                System.out.println("Welcome " + activeCustomer.getName());
                System.out.println("1 - See List Of Products");
                System.out.println("2 - Search Product");
                System.out.println("3 - Shop Online ");
                System.out.println("4 - View Preview Order");
                System.out.println("0 - Exit");
                System.out.println("---------------------------------------");
                choice = takeInput(choice, 0, 4);
                switch (choice) {
                    case 1:
                        //Branch List
                        activeCustomer.showListOfProduct(company);
                        //Product List
                        break;
                    case 2:
                        searchProductMenu(company, activeCustomer);
                        break;
                    case 3:
                        shopOnlineMenu(company, activeCustomer);
                        break;
                    case 4:
                        activeCustomer.showOrders();
                        break;
                }
            }
        } else
            System.out.println("There is no such customer in the system!!");
    }

    /**
     *Register menu make registration for new Customers
     * @param company Company Class Object
     * @return New Created Customer
     */
    public static Customer registerMenu(Company company) {
        Scanner readString = new Scanner(System.in);
        String name, surname, mail, password;
        System.out.println("---------------------------------------");
        System.out.println("Enter Name:");
        name = readString.next();
        System.out.println("Enter Surname:");
        surname = readString.next();
        System.out.println("Enter Mail:");
        mail = readString.next();
        System.out.println("Enter Password:");
        password = readString.next();
        System.out.println("---------------------------------------");
        Customer newCustomer = new Customer(name, surname, mail, password, -1);
        company.getCustomers().add(newCustomer);
        newCustomer.setId(company.getCustomers().getSize());
        System.out.println("Id: " + newCustomer.getId() + " Name: " + newCustomer.getName() + " Surname : " + newCustomer.getSurname()
                + " Email : "  + newCustomer.getEmail() + " Password : " + newCustomer.getPassword());
        return newCustomer;
    }

    /**
     * Admin menu has Customer operations.Such as add/remove branch and branch employee,show branches.
     * @param company Company Class Object.
     */
    public static void adminMenu(Company company) {
        String branchName;

        Scanner readString = new Scanner(System.in);
        int choice = -1, branchChoice = 0, employeeChoice = 0, branchId = 0;
        Branch tempBranch;
        while (choice != 0) {
            System.out.println("---------------------------------------");
            System.out.println("Welcome Admin!");
            System.out.println("1 - Add A Branch");
            System.out.println("2 - Remove A Branch");
            System.out.println("3 - Add A Branch Employee");
            System.out.println("4 - Remove A Branch Employee");
            System.out.println("5 - Query Products Need To Be Supplied");
            System.out.println("6 - Show Branches And Their Employees");
            System.out.println("0 - Exit");
            System.out.println("---------------------------------------");
            choice = takeInput(choice, 0, 6);
            switch (choice) {
                case 1:
                    //Show Branch List
                    company.getAdmin().showBranches(company.getBranches());
                    System.out.println("Enter Branch Name for Add Branch : ");
                    branchName = readString.next();
                    Branch newBranch = new Branch(branchName);
                    //Add Branch Operation Functions
                    company.getAdmin().addBranch(company.getBranches(), newBranch);
                    System.out.println("Branch Added...");
                    company.getAdmin().showBranches(company.getBranches());
                    //Show Branch List
                    break;
                case 2:
                    //Show Branch List
                    company.getAdmin().showBranches(company.getBranches());
                    System.out.println("Enter Branch number for Remove Branch : ");
                    branchId = takeInput(branchId, 1, company.getBranches().getSize());
                    //Remove Branch Operation Functions
                    company.getAdmin().removeBranch(company.getBranches(), (Branch) company.getBranches().getArrayElement(branchId - 1));
                    //Show Branch List
                    company.getAdmin().showBranches(company.getBranches());
                    break;
                case 3:
                    if (company.getBranches().getSize() > 0) {
                        System.out.println("Enter Branch Employee Information For Add Branch Employee");
                        System.out.println("Employee Name:");
                        String employeeName = readString.next();
                        System.out.println("Employee Surname:");
                        String employeeSurname = readString.next();
                        System.out.println("Employee Email:");
                        String employeeEmail = readString.next();
                        System.out.println("Employee Password:");
                        String employeePassword = readString.next();
                        BranchEmployee newEmployee = new BranchEmployee(employeeName, employeeSurname, employeeEmail, employeePassword, -1);
                        //Branch List
                        company.getAdmin().showBranches(company.getBranches());
                        branchChoice = -1;
                        branchChoice = takeInput(branchChoice, 1, company.getBranches().getSize());
                        //Employee Adding Functions
                        tempBranch = (Branch) company.getBranches().getArrayElement(branchChoice - 1);
                        newEmployee.setOwnBranch(tempBranch);
                        company.getAdmin().addEmployee(tempBranch.getBranchEmployees(), newEmployee);
                        //Branch List
                        company.getAdmin().showBranches(company.getBranches());
                    } else {
                        System.out.println("There is no branch!Please Add Branch First!");
                    }
                    break;
                case 4:
                    int removeBranch = 0;
                    if (company.getBranches().getSize() > 0) {
                        //Branch List
                        company.getAdmin().showBranches(company.getBranches());
                        System.out.println("Select Branch For Remove Employee");
                        removeBranch = takeInput(removeBranch, 1, company.getBranches().getSize());
                        tempBranch = (Branch) company.getBranches().getArrayElement(removeBranch - 1);

                        if (tempBranch.getBranchEmployees().getSize() > 0) {
                            //Employee List on Branch
                            tempBranch.showEmployees();
                            employeeChoice = takeInput(employeeChoice, 1, tempBranch.getBranchEmployees().getSize());
                            //Employee Removing Functions
                            company.getAdmin().removeEmployee(tempBranch.getBranchEmployees(),
                                    (BranchEmployee) tempBranch.getBranchEmployees().getArrayElement(employeeChoice - 1));
                            tempBranch.showEmployees();

                        } else {
                            System.out.println("There is no Employee!Please Add Employee First!");
                        }
                    } else {
                        System.out.println("There is no branch!Please Add Branch First!");
                    }
                    break;
                case 5:
                    System.out.println("Products Need To Be Supplied");
                    //Query List
                    break;
                case 6:
                    System.out.println("--Branches And Their Employees--");
                    company.getAdmin().showBranches(company.getBranches());
                    break;
            }
        }
    }

    /**
     * Employee menu has Employee operations.Such as add/remove product make sales,show orders.
     * @param company Company Class Object.
     */
    public static void employeeMenu(Company company) {
        int choice = -1,customerNumber = -1;
        String email, password;
        Scanner readString = new Scanner(System.in);
        System.out.println("Enter Email:");
        email = readString.next();
        System.out.println("Enter Your Password");
        password = readString.next();
        //Login Test Functions
        BranchEmployee activeEmployee = searchEmployee(company, new BranchEmployee("temp", "temp", email, password, -1));
        if (activeEmployee != null) {
            System.out.println("Welcome " + activeEmployee.getName());
            System.out.println("Your Branch is " + activeEmployee.getOwnBranch().getBranchName());
            while (choice != 0) {
                System.out.println("---------------------------------------");
                System.out.println("1 - Inquire About The Product In Stock");
                System.out.println("2 - Add New Product");
                System.out.println("3 - Remove Product");
                System.out.println("4 - Make Sales");
                System.out.println("5 - Access The Customer Order");
                System.out.println("0 - Exit");
                System.out.println("---------------------------------------");
                choice = takeInput(choice, 0, 5);
                switch (choice) {
                    case 1:
                        System.out.println("------------- " + activeEmployee.getOwnBranch() + " -------------");
                        activeEmployee.showChairStock(activeEmployee.getOwnBranch());
                        activeEmployee.showDeskStock(activeEmployee.getOwnBranch());
                        activeEmployee.showMeetingTableStock(activeEmployee.getOwnBranch());
                        activeEmployee.showOfficeCabinetStock(activeEmployee.getOwnBranch());
                        activeEmployee.showBookCaseStock(activeEmployee.getOwnBranch());
                        //Show Stock
                        break;
                    case 2:
                        Furniture newFurniture = addProductMenu();
                        if (newFurniture == null)
                            break;
                        if (newFurniture.getTypeProduct().equals("Chair")) {
                          activeEmployee.addFurniture(activeEmployee.getOwnBranch().getChairs(), (Chair) newFurniture);
                        }
                        if (newFurniture.getTypeProduct().equals("Desk")) {
                            activeEmployee.addFurniture(activeEmployee.getOwnBranch().getDesks(), (Desk) newFurniture);
                        }
                        if (newFurniture.getTypeProduct().equals("Meeting Table")) {
                            activeEmployee.addFurniture(activeEmployee.getOwnBranch().getMeetingTables(), (MeetingTable) newFurniture);
                        }
                        if (newFurniture.getTypeProduct().equals("Office Cabinet")) {
                            activeEmployee.addFurniture(activeEmployee.getOwnBranch().getOfficeCabinet(), (OfficeCabinet) newFurniture);
                        }
                        if (newFurniture.getTypeProduct().equals("Book Case")) {
                            activeEmployee.addFurniture(activeEmployee.getOwnBranch().getBookCases(), (BookCase) newFurniture);
                        }
                        break;
                    case 3:
                        removeProductMenu(activeEmployee);
                        break;
                    case 4:
                        System.out.println("Make Sells");
                        makeSellsMenu(company);
                        break;
                    case 5:
                        System.out.println("Order List\n\n");
                        System.out.println("Customer Number");
                        customerNumber = takeInput(customerNumber,1,company.getCustomers().getSize());
                        activeEmployee.accessCustomerOrder(company.getCustomers(),customerNumber);
                        break;
                }
            }
        } else
            System.out.println("There is no such employee in the system!");
    }

    /**
     * Searches for the selected employee in company.
     * @param company Company Class Object
     * @param searchEmployee Selected Employee Object
     * @return Founded Employee
     */
    public static BranchEmployee searchEmployee(Company company, BranchEmployee searchEmployee) {
        for (int i = 0; i < company.getBranches().getSize(); i++) {
            Branch temp = (Branch) company.getBranches().getArrayElement(i);
            if (temp.getBranchEmployees().search(searchEmployee) != null)
                return temp.getBranchEmployees().search(searchEmployee);
        }
        return null;
    }

    /**
     * Searches for the selected Customer in company.
     * @param company Company Class Object
     * @param searchCustomer Selected Customer Object
     * @return Founded Employee
     */
    public static Customer searchCustomer(Company company, Customer searchCustomer) {
        if (company.getCustomers().search(searchCustomer) != null)
            return company.getCustomers().search(searchCustomer);
        return null;
    }

    /**
     * It operate make sale operation for Branch Employees
     * @param company Company Class Object.
     */
    public static void makeSellsMenu(Company company){
        String email, password;
        Scanner readString = new Scanner(System.in);
        System.out.println("---------------------------------------");
        System.out.println("Enter Customer Email:");
        email = readString.next();
        System.out.println("Enter Customer Password:");
        password = readString.next();
        System.out.println("---------------------------------------");
        Customer activeCustomer = searchCustomer(company,new Customer("temp","temp",email,password,-1));
        if (activeCustomer == null){
            System.out.println("There is no such a customer.You are directed to create a user menu...");
            System.out.println("Please Enter User Information");
           activeCustomer =  registerMenu(company);
        }
        else {
            System.out.println("User Found..");
        }
        System.out.println("Select Branch For Make Sales");
        shopOnlineMenu(company,activeCustomer);
    }

    /**
     * It has menu for create product and return created product.
     * @return created product object
     */
    public static Furniture addProductMenu() {
        int choiceModel = 0;
        int choice = 0;
        System.out.println("---------------------------------------");
        System.out.println("Product Types");
        System.out.println("1 - Chair");
        System.out.println("2 - Desk");
        System.out.println("3 - Meeting Table");
        System.out.println("4 - Office Cabinet");
        System.out.println("5 - Book Case");
        System.out.println("---------------------------------------");
        choice = takeInput(choice, 1, 5);
        switch (choice) {
            case 1:
                //Chair Type List
                Chair newChair = new Chair("Undetermined", "Undetermined");
                for (int i = 0; i < newChair.getModels().length; i++) {
                    System.out.println(i + 1 + "." + newChair.getModels()[i]);
                }
                choiceModel = takeInput(choiceModel, 1, newChair.getModels().length);
                newChair.setModelName(newChair.getModels()[choiceModel - 1]);
                for (int i = 0; i < newChair.getColors().length; i++) {
                    System.out.println(i + 1 + "." + newChair.getColors()[i]);
                }
                choiceModel = 0;
                choiceModel = takeInput(choiceModel, 1, newChair.getColors().length);
                newChair.setColorName(newChair.getColors()[choiceModel - 1]);
                return (Furniture) newChair;
            case 2:
                Desk newDesk = new Desk("Undetermined", "Undetermined");
                for (int i = 0; i < newDesk.getModels().length; i++) {
                    System.out.println(i + 1 + "." + newDesk.getModels()[i]);
                }
                choiceModel = 0;
                choiceModel = takeInput(choiceModel, 1, newDesk.getModels().length);
                newDesk.setModelName(newDesk.getModels()[choiceModel - 1]);
                for (int i = 0; i < newDesk.getColors().length; i++) {
                    System.out.println(i + 1 + "." + newDesk.getColors()[i]);
                }
                choiceModel = 0;
                choiceModel = takeInput(choiceModel, 1, newDesk.getColors().length);
                newDesk.setColorName(newDesk.getColors()[choiceModel - 1]);
                return (Furniture) newDesk;
            case 3:
                MeetingTable newTable = new MeetingTable("Undetermined", "Undetermined");
                for (int i = 0; i < newTable.getModels().length; i++) {
                    System.out.println(i + 1 + "." + newTable.getModels()[i]);
                }
                choiceModel = 0;
                choiceModel = takeInput(choiceModel, 1, newTable.getModels().length);
                newTable.setModelName(newTable.getModels()[choiceModel - 1]);
                for (int i = 0; i < newTable.getColors().length; i++) {
                    System.out.println(i + 1 + "." + newTable.getColors()[i]);
                }
                choiceModel = 0;
                choiceModel = takeInput(choiceModel, 1, newTable.getColors().length);
                newTable.setColorName(newTable.getColors()[choiceModel - 1]);
                return (Furniture) newTable;
            case 4:
                OfficeCabinet newCabinet = new OfficeCabinet("Undetermined");
                for (int i = 0; i < newCabinet.getModels().length; i++) {
                    System.out.println(i + 1 + "." + newCabinet.getModels()[i]);
                }
                choiceModel = 0;
                choiceModel = takeInput(choiceModel, 1, newCabinet.getModels().length);
                newCabinet.setModelName(newCabinet.getModels()[choiceModel - 1]);
                return (Furniture) newCabinet;
            case 5:
                BookCase newCase = new BookCase("Undetermined");
                for (int i = 0; i < newCase.getModels().length; i++) {
                    System.out.println(i + 1 + "." + newCase.getModels()[i]);
                }
                choiceModel = 0;
                choiceModel = takeInput(choiceModel, 1, newCase.getModels().length);
                newCase.setModelName(newCase.getModels()[choiceModel - 1]);
                return (Furniture) newCase;
        }
        return null;
    }

    /**
     * It has menu for remove product and delete from product array.
     * @param activeEmployee active Employee in system
     */
    public static void removeProductMenu(BranchEmployee activeEmployee) {
        int choiceModel = 0;
        int choice = 0;
        Branch activeBranch = activeEmployee.getOwnBranch();
        System.out.println("Select Product Type For Remove");
        System.out.println("1 - Chair");
        System.out.println("2 - Desk");
        System.out.println("3 - Meeting Table");
        System.out.println("4 - Office Cabinet");
        System.out.println("5 - Book Case");
        choice = takeInput(choice, 1, 5);
        switch (choice) {
            case 1:
                if (activeBranch.getChairs().getSize() != 0) {
                    activeEmployee.showChairStock(activeBranch);
                    choiceModel = 0;
                    choiceModel = takeInput(choiceModel, 1, activeBranch.getChairs().getSize());
                    activeEmployee.removeFurniture(activeBranch.getChairs(), (Chair) activeBranch.getChairs().getArrayElement(choiceModel - 1));
                    System.out.println("Chair Deleted");
                } else
                    System.out.println("No Chair Stock!");
                break;
            case 2:
                if (activeBranch.getDesks().getSize() != 0) {
                    activeEmployee.showDeskStock(activeBranch);
                    choiceModel = 0;
                    choiceModel = takeInput(choiceModel, 1, activeBranch.getDesks().getSize());
                    activeEmployee.removeFurniture(activeBranch.getDesks(), (Desk) activeBranch.getDesks().getArrayElement(choiceModel - 1));
                    System.out.println("Desk Deleted");
                } else
                    System.out.println("No Desk Stock!");
                break;
            case 3:
                if (activeBranch.getMeetingTables().getSize() != 0) {
                    activeEmployee.showMeetingTableStock(activeBranch);
                    choiceModel = 0;
                    choiceModel = takeInput(choiceModel, 1, activeBranch.getMeetingTables().getSize());
                    activeEmployee.removeFurniture(activeBranch.getMeetingTables(), (MeetingTable) activeBranch.getMeetingTables().getArrayElement(choiceModel - 1));
                    System.out.println("Meeting Table Deleted");
                } else
                    System.out.println("No Meeting Table Stock!");
                break;
            case 4:
                if (activeBranch.getOfficeCabinet().getSize() != 0) {
                    activeEmployee.showOfficeCabinetStock(activeBranch);
                    choiceModel = 0;
                    choiceModel = takeInput(choiceModel, 1, activeBranch.getOfficeCabinet().getSize());
                    activeEmployee.removeFurniture(activeBranch.getOfficeCabinet(), (OfficeCabinet) activeBranch.getOfficeCabinet().getArrayElement(choiceModel - 1));
                    System.out.println("Office Cabinet Deleted");
                } else
                    System.out.println("No Office Cabinet Stock!");
                break;
            case 5:
                if (activeBranch.getBookCases().getSize() != 0) {
                    activeEmployee.showBookCaseStock(activeBranch);
                    choiceModel = 0;
                    choiceModel = takeInput(choiceModel, 1, activeBranch.getBookCases().getSize());
                    activeEmployee.removeFurniture(activeBranch.getBookCases(), (BookCase) activeBranch.getBookCases().getArrayElement(choiceModel - 1));
                    System.out.println("Book Case Deleted");
                } else
                    System.out.println("No Book Case Stock!");
                break;
        }
    }

    /**
     * Take Input With Error(Exception) Handling
     * @param choice input for selection variable
     * @param lowBound low bound of choice
     * @param highBound high bound of choice
     * @return final choice
     */
    public static int takeInput(int choice, int lowBound, int highBound) {
        Scanner scanInt = new Scanner(System.in);
        do {
            System.out.println("Enter Your Choice: ");
            try {
                choice = scanInt.nextInt();
            } catch (InputMismatchException e) {
                System.out.println("Invalid number!");
            }
            scanInt.nextLine();
        } while (choice < lowBound || highBound < choice);
        return choice;
    }

    /**
     * Operate shop online for Customers.
     * @param company Company Class Object.
     * @param activeCustomer active Customer in the system.
     */
    public static void shopOnlineMenu(Company company, Customer activeCustomer) {
        int branchChoice = -1, productChoice = -1, productTypeChoice = -1,count =-1;
        String address;
        String phone;
        Scanner readString = new Scanner(System.in);
        System.out.println("Choose Branch:");
        if (company.getBranches().getSize() != 0) {
            for (int i = 0; i < company.getBranches().getSize(); i++) {
                Branch temp = (Branch) company.getBranches().getArrayElement(i);
                System.out.println(i + 1 + "." + temp.getBranchName());
            }
            branchChoice = takeInput(branchChoice, 1, company.getBranches().getSize());
            Branch activeBranch = (Branch) company.getBranches().getArrayElement(branchChoice - 1);
            if (activeBranch.getBranchEmployees().getSize() != 0) {
                BranchEmployee tEmployee = (BranchEmployee) activeBranch.getBranchEmployees().getArrayElement(0);
                System.out.println("---------------------------------------");
                System.out.println("Choose Product Type:");
                System.out.println("1 - Chair");
                System.out.println("2 - Desk");
                System.out.println("3 - Meeting Table");
                System.out.println("4 - Office Cabinet");
                System.out.println("5 - Book Case");
                System.out.println("0 - Exit");
                System.out.println("---------------------------------------");
                productTypeChoice = takeInput(productTypeChoice, 0, 5);
                switch (productTypeChoice) {
                    case 1:
                        if (activeBranch.getChairs().getSize() != 0) {
                            tEmployee.showChairStock(activeBranch);
                            System.out.println("Select Product For Buy");
                            productChoice = 0;
                            productChoice = takeInput(productChoice, 1, activeBranch.getChairs().getSize());
                            Chair tempChair = (Chair) activeBranch.getChairs().getArrayElement(productChoice - 1);
                            Furniture furnitureOrder = new Furniture(tempChair.getModelName(), tempChair.getColorName(), "Chair");
                            activeCustomer.getOrders().add(furnitureOrder);
                            activeBranch.getChairs().delete((Chair) activeBranch.getChairs().getArrayElement(productChoice - 1));
                            count = 1;
                        } else
                            System.out.println("There is no chair stock in selected branch!");
                        break;
                    case 2:
                        if (activeBranch.getDesks().getSize() != 0) {
                            tEmployee.showDeskStock(activeBranch);
                            System.out.println("Select Product For Buy");
                            productChoice = 0;
                            productChoice = takeInput(productChoice, 1, activeBranch.getDesks().getSize());
                            Desk tempDesk = (Desk) activeBranch.getDesks().getArrayElement(productChoice - 1);
                            Furniture furnitureOrder = new Furniture(tempDesk.getModelName(), tempDesk.getColorName(), "Chair");
                            activeCustomer.getOrders().add(furnitureOrder);
                            activeBranch.getDesks().delete((Desk) activeBranch.getDesks().getArrayElement(productChoice - 1));
                            count = 1;
                        } else
                            System.out.println("There is no desk stock in selected branch!");
                        break;
                    case 3:
                        if (activeBranch.getMeetingTables().getSize() != 0) {
                            tEmployee.showMeetingTableStock(activeBranch);
                            System.out.println("Select Product For Buy");
                            productChoice = 0;
                            productChoice = takeInput(productChoice, 1, activeBranch.getMeetingTables().getSize());
                            MeetingTable tempTable = (MeetingTable) activeBranch.getMeetingTables().getArrayElement(productChoice - 1);
                            Furniture furnitureOrder = new Furniture(tempTable.getModelName(), tempTable.getColorName(), "Chair");
                            activeCustomer.getOrders().add(furnitureOrder);
                            activeBranch.getMeetingTables().delete((MeetingTable) activeBranch.getMeetingTables().getArrayElement(productChoice - 1));
                            count = 1;
                        } else
                            System.out.println("There is no meeting table stock in selected branch!");
                        break;
                    case 4:
                        if (activeBranch.getOfficeCabinet().getSize() != 0) {
                            tEmployee.showOfficeCabinetStock(activeBranch);
                            System.out.println("Select Product For Buy");
                            productChoice = 0;
                            productChoice = takeInput(productChoice, 1, activeBranch.getOfficeCabinet().getSize());
                            OfficeCabinet tempCabinet = (OfficeCabinet) activeBranch.getOfficeCabinet().getArrayElement(productChoice - 1);
                            Furniture furnitureOrder = new Furniture(tempCabinet.getModelName(), tempCabinet.getColorName(), "Chair");
                            activeCustomer.getOrders().add(furnitureOrder);
                            activeBranch.getOfficeCabinet().delete((OfficeCabinet) activeBranch.getOfficeCabinet().getArrayElement(productChoice - 1));
                            count = 1;
                        } else
                            System.out.println("There is no office cabinet stock in selected branch!");
                        break;
                    case 5:
                        if (activeBranch.getBookCases().getSize() != 0) {
                            tEmployee.showBookCaseStock(activeBranch);
                            System.out.println("Select Product For Buy");
                            productChoice = 0;
                            productChoice = takeInput(productChoice, 1, activeBranch.getBookCases().getSize());
                            BookCase tempCase = (BookCase) activeBranch.getBookCases().getArrayElement(productChoice - 1);
                            Furniture furnitureOrder = new Furniture(tempCase.getModelName(), tempCase.getColorName(), "Chair");
                            activeCustomer.getOrders().add(furnitureOrder);
                            activeBranch.getBookCases().delete((BookCase) activeBranch.getBookCases().getArrayElement(productChoice - 1));
                            count = 1;
                        } else
                            System.out.println("There is no office cabinet stock in selected branch!");
                        break;
                }
                if (productChoice != 0 && count == 1) {
                    System.out.println("Enter Address:");
                    address = readString.next();
                    System.out.println("Enter Phone Number:");
                    phone = readString.next();
                    activeCustomer.setAddress(address);
                    activeCustomer.setPhone(phone);
                    System.out.println("Your order has been completed...");
                }
            } else
                System.out.println("There is no stock!!");
        } else
            System.out.println("There is no branch in company!!");
    }

    /**
     * Operate search product for active Customer.
     * @param company Company Class Object.
     * @param activeCustomer active Customer in system.
     */
    public static void searchProductMenu(Company company, Customer activeCustomer) {
        System.out.println("---------------------------------------");
        System.out.println("Select Product Type For Search");
        Furniture newFurniture = addProductMenu();
        activeCustomer.searchProduct(company,newFurniture);
    }
}
