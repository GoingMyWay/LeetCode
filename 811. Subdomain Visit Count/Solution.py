class Solution(object):
    def subdomainVisits(self, cpdomains):
        """
        :type cpdomains: List[str]
        :rtype: List[str]
        """
        temp_hash = {}
        for v in cpdomains:
            value, domain = v.split()
            splited = domain.split(.)
            keys = [..join(splited[i:]) for i in range(len(splited))]
            for k in keys:
                temp_hash[k] = temp_hash.get(k, 0) + int(value)
                
        return [%s %s % (v, k) for k, v in temp_hash.items()]

