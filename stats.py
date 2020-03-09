class Stats:
    def __init__(self, command, id):
        self.command = command
        self.response = None
        self.id = id
        self.duration = None

    def add_response(self, response):
        self.response = response
        # self.print_stats()

    def print_stats(self):
        print('\nid: %s' % self.id)
        print('command: %s' % self.command)
        print('response: %s' % self.response)

    def got_response(self):
        if self.response is None:
            return False
        else:
            return True

    def return_stats(self):
        str = ''
        str += '\nid: %s\n' % self.id
        str += 'command: %s\n' % self.command
        str += 'response: %s\n' % self.response
        return str