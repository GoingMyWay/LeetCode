class Solution(object):
    def findDuplicate(self, paths):
        """
        :type paths: List[str]
        :rtype: List[List[str]]
        """
        m_map = {}
        for p_files in paths:
            p_dir = p_files.split()
            for f in p_dir[1:]:
                idx = f.find('(')
                content = f[idx+1:-1]
                if content not in m_map:
                    m_map[content] = []
                m_map[content].append('/'.join([p_dir[0], f[:idx]]))

        return [path_list for content, path_list in m_map.items() if len(path_list) > 1]
