package hw1;

/**
 * Administrator Class for admin operations.
 * Administrator can show branches,add and remove branch,add and remove employee to system.
 * @author Erdi Bayir
 * @since 13.03.2021
 */
public class Administrator extends Person implements IAdministrator{
    /**
     * Constructor for set name,surname,email,password and id
     * @param name name of administrator
     * @param surname surname of administrator
     * @param email email of administrator
     * @param password password of administrator
     * @param id id of administrator
     */
    public Administrator(String name, String surname, String email, String password, int id) {
        super(name, surname, email, password, id);
    }

    /**
     * Add branch to furniture company system.
     * @param branches array of branches in company
     * @param newBranch new element of branch array
     */
    public void addBranch(MyArray<Branch> branches, Branch newBranch){
        branches.add(newBranch);
    }

    /**
     * Remove branch from furniture company system.
     * @param branches array of branches in company system
     * @param removeBranch Array element to delete from branches
     */
    public void removeBranch(MyArray<Branch> branches,Branch removeBranch){
        branches.delete(removeBranch);
    }

    /**
     * Add Employee to company system
     * @param employees array of branch employees in company system
     * @param newEmployee new element of employee array
     */
    public void addEmployee(MyArray<BranchEmployee> employees,BranchEmployee newEmployee){
        employees.add(newEmployee);
    }

    /**
     * Remove Employee from company system
     * @param employees array of branch employees in company system
     * @param removeEmployee array element to delete from branch employees
     */
    public void removeEmployee(MyArray<BranchEmployee> employees,BranchEmployee removeEmployee){
        employees.delete(removeEmployee);
    }

    /**
     * Show all branches and their branch employees in company
     * @param branches array of branches in company system
     */
    public void showBranches(MyArray<Branch> branches){
        for (int i = 0 ; i < branches.getSize();i++){
           Branch tempBranch = (Branch) branches.getArrayElement(i);
           System.out.print(i+1 + ".");
           System.out.println(tempBranch.toString());
           tempBranch.showEmployees();
        }
    }
}
