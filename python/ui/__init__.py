import pygame

class ui:
    def __init__(self, rows):
        pygame.init()
        self.running = True
        self.rows = rows
        self.size = self.weight, self.height = 640, 400
        self.display = pygame.display.set_mode(self.size)
        self.clock = pygame.time.Clock()

    def on_quit(self):
        pygame.quit()

    def draw_grid(self.rows):
        for row in self.rows:
            for node in row:
                node.draw_grid(self.rows)

    def on_execute(self):

        while( self.running ):
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    self.running = False

        self.on_quit()
    

