import pygame

class Node:
    def __init__(self, row, col, width):
        self.row = row
        self.col = col
        self.width = width
        self.x = row*width
        self.y = row*width
        self.isWall = False
        self.color = None
    
    def set_wall(self):
        self.isWall = True
    
    def set_color(self, color):
        self.color = color
    
    def draw_node(self, window):
        pygame.draw.rect(window, self.color, (self.x, self.y, self.width, self.width), 1)
    
    def draw_grid(self, rows):
        