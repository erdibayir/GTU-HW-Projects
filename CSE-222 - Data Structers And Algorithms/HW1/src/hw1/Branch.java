package hw1;

/**
 * Branch Class for Branch Operations.
 * Branch Class have product arrays and Employee Array.
 * @author Erdi Bayir
 * @since 13.03.2021
 */
public class Branch {
    protected String branchName;
    protected MyArray<Chair> chairs = new MyArray<Chair>();
    protected MyArray<Desk> desks = new MyArray<Desk>();
    protected MyArray<MeetingTable> meetingTables = new MyArray<MeetingTable>();
    protected MyArray<BookCase> bookCases = new MyArray<BookCase>();
    protected MyArray<OfficeCabinet> officeCabinets = new MyArray<OfficeCabinet>();
    protected MyArray<BranchEmployee> BranchEmployees = new MyArray<BranchEmployee>();

    /**
     * Default Constructor
     */
    public Branch() {
    }

    /**
     *Constructor for create Branch with name.
     * @param branchName name of branch
     */
    public Branch(String branchName) {
        this.branchName = branchName;
    }

    /**
     * Getter of Branch name
     * @return Branch name
     */
    public String getBranchName() {
        return branchName;
    }

    /**
     * Getter of Chairs array
     * @return chairs array
     */
    public MyArray<Chair> getChairs() {
        return chairs;
    }

    /**
     * Getter of Desks
     * @return Desks
     */
    public MyArray<Desk> getDesks() {
        return desks;
    }

    /**
     * Getter of Meeting Tables
     * @return Meeting Tables
     */
    public MyArray<MeetingTable> getMeetingTables() {
        return meetingTables;
    }

    /**
     * Getter of Book Cases
     * @return Book Cases
     */
    public MyArray<BookCase> getBookCases() {
        return bookCases;
    }

    /**
     * Getter of Office Cabinets
     * @return Office Cabinets
     */
    public MyArray<OfficeCabinet> getOfficeCabinet() {
        return officeCabinets;
    }

    /**
     * Getter of Branch Employees
     * @return Branch Employees
     */
    public MyArray<BranchEmployee> getBranchEmployees() {
        return BranchEmployees;
    }

    /**
     * Override toString for Branch
     * @return Branch name
     */
    @Override
    public String toString() {
        return "Branch = " + branchName;
    }

    /**
     * Show All Employees in Branch
     */
    public void showEmployees() {
        for (int j = 0 ; j < BranchEmployees.getSize();j++){
            BranchEmployee tempEmployee = (BranchEmployee) BranchEmployees.getArrayElement(j);
            System.out.print("\t");
            System.out.print(j+1 + ".");
            tempEmployee.showEmployeeInfo();
        }
    }
}
