class athlete_list(list):
    def __init__(self, name, dob=None, times=[]):
        list.__init__([])
        self.name = name
        self.dob = dob
        self.extend(times)
    
    def top3(self):
        return(str(sorted(set([sanitize(each_t) for each_t in self]))[0:3]))
