"""
# Employee info
class Employee(object):
    def __init__(self, id, importance, subordinates):
        # It's the unique id of each node.
        # unique id of this employee
        self.id = id
        # the importance value of this employee
        self.importance = importance
        # the id of direct subordinates
        self.subordinates = subordinates
"""
class Solution(object):
    def getImportance(self, employees, id):
        """
        :type employees: Employee
        :type id: int
        :rtype: int
        """
        hash_map = {}
        for employee in employees:
            hash_map[employee.id] = [employee.subordinates, employee.importance]
        
        val_import = self.dfs(hash_map, id)
        return val_import
        
    def dfs(self, hash_map, e_id):
        val = hash_map[e_id][1]
        for emp_id in hash_map[e_id][0]:
            val += self.dfs(hash_map, emp_id)
        return val
