package hw1;

/**
 * Administrator interface for company
 */
public interface IAdministrator {
    void addBranch(MyArray<Branch> branches, Branch newBranch);
    void removeBranch(MyArray<Branch> branches,Branch removeBranch);
    void addEmployee(MyArray<BranchEmployee> employees,BranchEmployee newEmployee);
    void removeEmployee(MyArray<BranchEmployee> employees,BranchEmployee removeEmployee);
    void showBranches(MyArray<Branch> branches);
}
