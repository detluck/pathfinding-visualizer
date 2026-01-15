import pygame
from model import Node
from ui.settings import BLACK

class Ui:
    def __init__(self, rows, cols):
        pygame.init()
        self.running = True
        self.rows = rows
        self.cols = cols
        self.size = self.weight, self.height = 1280, 720
        self.display = pygame.display.set_mode(self.size)
        self.clock = pygame.time.Clock()

    def draw_grid(self):
        grid = []
        width = self.weight/self.rows
        height = self.height/self.cols
        for i in range(self.rows):
            grid.append([])
            for j in range (self.cols):
                node = Node(i, j, width, height)
                grid[i].append(node)
        return grid
    
    def draw_all(self, grid):
        self.display.fill(BLACK)
        for row in grid:
            for node in row:
                node.draw_node(self.display)
        pygame.display.update()
