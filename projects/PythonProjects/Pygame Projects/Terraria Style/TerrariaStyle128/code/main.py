import pygame
import sys
from globals import *
from scene import Scene
from pytmx.util_pygame import load_pygame


class Tile(pygame.sprite.Sprite):
    def __init__(self,pos,surf,groups):
        super().__init__(groups)
        self.image = surf
        self.rect = self.image.get_rect(topleft = pos)

class Game:
    def __init__(self):
        pygame.init()
        pygame.display.set_caption('Terraria Style')
        self.screen = pygame.display.set_mode((SCREENWIDTH, SCREENHEIGHT))
        self.clock = pygame.time.Clock()
        self.level = True

        self.scene = Scene(self)

        # *** Start TMX To Python/Pygame/Pytmx ***
        
        # Variable for Tiled (tmx file)
        tmx_data = load_pygame('/home/deck/Desktop/Python/Pygame Projects/Terraria Style/TerrariaStyle128/data/export/basic.tmx')
            # print(dir(tmx_data))
            
        sprite_group = pygame.sprite.Group()
        
        
        # Cycle Through All Layers
        for layer in tmx_data.visible_layers:
            # if layer.name in ('Ground', 'Plants & Rocks', 'Floor', 'Roads'): # Not The Ideal Approach.
            if hasattr(layer,'data'):
                # print(layer) # Info
                for x,y,surf in layer.tiles():
                    pos = (x * 128, y * 128)
                    Tile(pos = pos, surf = surf, groups = sprite_group)
                    # for x,y,surf in layer.tiles(): # Get All The Information.
                    #      print(x * 128)
                    #      print(y * 128)
                    #      print(surf)
                    
        for obj in tmx_data.objects:
            pos = obj.x,obj.y
            if obj.type in ('Building', 'Vegetation'):  # *** HERE YOU WANT TO HAVE CLEAR NAMES FOR YOUR OBJECTS!!!  TREE, CASTLE, ETC INSTEAD OF "OBJ.IMAGE" DO LIKE OBJ.TREE ***
                Tile(pos = pos, surf = obj.image, groups = sprite_group)
                
            
        
        # Get Layers
        # print(tmx_data.layers) # Get All Layers
        # for layer in tmx_data.visible_layers: # Get Visible Layers
        #     print(layer)
            
        # print(tmx_data.layernames) # Get All Layer Names As Dictionaries.
        
        # print(tmx_data.get_layer_by_name('Floor')) # Get One layer By Name
        
        # for obj in tmx_data.objectgroups: # Get Object Layers
        #     print(obj)
            
        # Get Tiles
        # layer = tmx_data.get_layer_by_name('Floor')
        # print(dir(layer))
        # for x,y,surf in layer.tiles(): # Get All The Information.
        #      print(x * 128)
        #      print(y * 128)
        #      print(surf)
        
        # print(layer.data) # CSV Data
        # print(layer.name) # Name of the Layer in Tiled.
        # print(layer.id)   # Name of the ID in Tiled, if used.
        
        # Get Objects.
        object_layer = tmx_data.get_layer_by_name('Objects')
        # print(object_layer)
        # print(dir(object_layer))
        
        # 1 (FIRST) APPROACH!
        for obj in object_layer:
            # print(dir(obj))
            # print(obj.x)
            # print(obj.y)
            # print(obj.image) 
            if obj.type == 'Shape':
                # if obj.name == 'Marker':
                #     print(obj.x)
                #     print(obj.y)
                # if obj.name == 'Rectangle':
                #     print(obj.x)
                #     print(obj.y)
                #     print(obj.width)
                #     print(obj.height)
                #     print(obj.as_points)
                # if obj.name == 'Ellipse':
                #     print(dir(obj))
                    
                if obj.name == 'Polygon':
                    print(obj)
                    print(obj.as_points) # Returns The "POINTS" Of The Container The Ojbect Is In.
                    print(obj.points) # Returns The "POINTS" Of The "ACTUAL" Polygon/Shape.

        # 2 (SECOND) APPROACH!            
        # for obj in tmx_data.objects:
        #     print(obj)
        
        # *** End TMX To Python/Pygame/Pytmx ***

    def run(self):
        while self.level:
            self.update()
            self.draw()
        self.close()

    def update(self):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                self.level = False
        
        self.scene.update()
        pygame.display.update()
        self.clock.tick(FPS)

    def draw(self):
        self.scene.draw()

    def close(self):
        pygame.quit()
        sys.exit()

if __name__ == "__main__":
    game = Game()
    game.run()