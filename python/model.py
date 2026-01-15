import pygame
from settings import WHITE
class Node:
    def __init__(self, row, col, width, height):
        self.row = row
        self.col = col
        self.height = height
        self.width = width
        self.x = col*width
        self.y = row*height
        self.isWall = False
        self.color = WHITE
    
    def set_wall(self):
        self.isWall = True
    
    def set_color(self, color):
        self.color = color
    
    def draw_node(self, window):
        pygame.draw.rect(window, self.color, (self.x, self.y, self.width, self.height), 1)