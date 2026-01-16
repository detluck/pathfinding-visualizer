import pygame
from ui.settings import WHITE
class Button:
    def __init__(self, x, y, width, height, color, hover_color, text, surface ):
        self.x = x
        self.y = y
        self. width = width
        self.height = height
        self.rect = pygame.Rect(self.x, self.y, self.width, self.height)
        self.color = color
        self.hover_color = hover_color
        self.text = text
        self.surface = surface
        self.fotn = pygame.font.SysFont("Arial", 15)
    
    def draw_button(self):
        cursor = pygame.mouse.get_pos()
        color = self.hover_color if self.rect.collidepoint(cursor) else self.color
        pygame.draw.rect(self.surface, color, self.rect,  border_radius=10)
        text_surf = self.fotn.render(self.text, True, WHITE)
        text_rect = text_surf.get_rect(center = self.rect.center)
        self.surface.blit(text_surf, text_rect)

    def is_cklicked(self, event):
        if event.type == pygame.MOUSEBUTTONDOWN and event.button == 1:
            if self.rect.collidepoint(event.pos):
                return True
        return False
        
