class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        s = set()
        for _email in emails:
            _res = _email.split('@')
            _local_name, _domain_name = _res[0], _res[1]
            _true_name = _local_name.split('+')[0]
            s.add(''.join(_true_name.split('.')) + _domain_name)
        return len(s)

