import pygame
from model import Node
from ui.settings import BLACK

class Ui:
    def __init__(self, rows, cols, cell_size):
        pygame.init()
        self.running = True
        self.rows = rows
        self.cols = cols
        self.cell_size = cell_size
        self.size = self.weight, self.height = 1280, 720
        self.display = pygame.display.set_mode(self.size)

    def draw_grid(self, surface: pygame.Surface):
        grid = []
        for i in range(self.rows):
            grid.append([])
            for j in range (self.cols):
                node = Node(i, j, self.cell_size)
                grid[i].append(node)
        return grid
    
    def draw_all(self, grid, surface: pygame.Surface):
        width, height = surface.get_size()
        grid[5][5].set_wall()
        for row in grid:
            for node in row:
                if(node.isWall):
                    node.draw_node(surface)
        #vertical line
        for x in range(0, width, self.cell_size):
            pygame.draw.line(surface, (40, 40, 40), (x, 0), (x, height))
        #horizontal line
        for y in range(0, height, self.cell_size):
            pygame.draw.line(surface, (40, 40, 40), (0, y), (width, y))

        pygame.display.update()
