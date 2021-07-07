package hw1;

import java.util.ArrayList;

/**
 * Branch Class for Branch Operations.
 * Branch Class have product arrays and Employee Array.
 * @author Erdi Bayir
 * @since 13.03.2021
 */
public class Branch {
    protected String branchName;
    protected GTUHybridList<Chair> chairs = new GTUHybridList<Chair>();
    protected GTUHybridList<Desk> desks = new GTUHybridList<Desk>();
    protected GTUHybridList<MeetingTable> meetingTables = new GTUHybridList<MeetingTable>();
    protected GTUHybridList<BookCase> bookCases = new GTUHybridList<BookCase>();
    protected GTUHybridList<OfficeCabinet> officeCabinets = new GTUHybridList<OfficeCabinet>();
    protected GTUArrayList<BranchEmployee> BranchEmployees = new GTUArrayList<BranchEmployee>();

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
    public GTUHybridList<Chair> getChairs() {
        return chairs;
    }

    /**
     * Getter of Desks
     * @return Desks
     */
    public GTUHybridList<Desk> getDesks() {
        return desks;
    }

    /**
     * Getter of Meeting Tables
     * @return Meeting Tables
     */
    public GTUHybridList<MeetingTable> getMeetingTables() {
        return meetingTables;
    }

    /**
     * Getter of Book Cases
     * @return Book Cases
     */
    public GTUHybridList<BookCase> getBookCases() {
        return bookCases;
    }

    /**
     * Getter of Office Cabinets
     * @return Office Cabinets
     */
    public GTUHybridList<OfficeCabinet> getOfficeCabinet() {
        return officeCabinets;
    }

    /**
     * Getter of Branch Employees
     * @return Branch Employees
     */
    public GTUArrayList<BranchEmployee> getBranchEmployees() {
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
            BranchEmployee tempEmployee = (BranchEmployee) BranchEmployees.get(j);
            System.out.print("\t");
            System.out.print(j+1 + ".");
            tempEmployee.showEmployeeInfo();
        }
    }
}
