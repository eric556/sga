Buildings = {
    Houses = {
        Blue = {},
        Green = {}
    },
    SplitTemplate = {},
    Template = {},
    PkCenter = {},
    ShoppingCenter = {},
    Apartment1 = {},
    Apartment2 = {},
    Apartment3 = {},
    Apartment4 = {},
    Apartment5 = {},
    Station = {},
    School = {},
    Gym = {}
}

function Buildings.Houses.Blue.new(position)
    local entity = entityManager:createEntity()
    entity.name = "Blue_House " .. entity.id
    local transform = entity:addTransform()
    transform.position = position
    transform.scale = Vector2.new(3, 3)
    local sprite = entity:addSprite()
    sprite.textureRect = IntRect.new(240, 64, 80, 96)
    sprite.useTextureRect = true
    sprite.texture_id = "pokemon_sheet"
    return entity
end

function Buildings.Houses.Green.new(position)
    local entity = entityManager:createEntity()
    entity.name = "Green_House " .. entity.id
    local transform = entity:addTransform()
    transform.position = position
    transform.scale = Vector2.new(3, 3)
    local sprite = entity:addSprite()
    sprite.textureRect = IntRect.new(336, 64, 80, 96)
    sprite.useTextureRect = true
    sprite.texture_id = "pokemon_sheet"
    return entity
end

function Buildings.PkCenter.new(position)
    local PK_Center = entityManager:createEntity()
    PK_Center.name = 'PK_Center_' .. PK_Center.id
    local transformCompPK_Center = PK_Center:addTransform()
    transformCompPK_Center.position = Vector3.new(1032, 641, 0)
    transformCompPK_Center.scale = Vector2.new(1, 1)
    transformCompPK_Center.rotation = 0
    
    local PK_Center_Bottom = entityManager:createEntityOnParent(PK_Center)
    PK_Center_Bottom.name = 'PK_Center_' .. PK_Center.id .. '_Bottom_' .. PK_Center_Bottom.id
    local transformCompPK_Center_Bottom = PK_Center_Bottom:addTransform()
    transformCompPK_Center_Bottom.position = Vector3.new(0, 32, 0)
    transformCompPK_Center_Bottom.scale = Vector2.new(1, 1)
    transformCompPK_Center_Bottom.rotation = 0
    
    local spriteCompPK_Center_Bottom = PK_Center_Bottom:addSprite()
    spriteCompPK_Center_Bottom.texture_id = 'pokemon_sheet'
    spriteCompPK_Center_Bottom.useTextureRect = true
    spriteCompPK_Center_Bottom.textureRect = IntRect.new(432, 160, 80, 64)
    
    local PK_Center_Top = entityManager:createEntityOnParent(PK_Center)
    PK_Center_Top.name = 'PK_Center_' .. PK_Center.id .. '_Top_' .. PK_Center_Top.id
    local transformCompPK_Center_Top = PK_Center_Top:addTransform()
    transformCompPK_Center_Top.position = Vector3.new(0, 0, 2)
    transformCompPK_Center_Top.scale = Vector2.new(1, 1)
    transformCompPK_Center_Top.rotation = 0
    
    local spriteCompPK_Center_Top = PK_Center_Top:addSprite()
    spriteCompPK_Center_Top.texture_id = 'pokemon_sheet'
    spriteCompPK_Center_Top.useTextureRect = true
    spriteCompPK_Center_Top.textureRect = IntRect.new(432, 130, 80, 32)

    return PK_Center
end

function Buildings.ShoppingCenter.new(position)
    local shopping_center = entityManager:createEntity()
    shopping_center.name = 'shopping_center_' .. shopping_center.id
    local transformCompshopping_center = shopping_center:addTransform()
    if position ~= nil then
        transformCompshopping_center.position = position
    end
    transformCompshopping_center.scale = Vector2.new(1, 1)
    transformCompshopping_center.rotation = 0

    local spriteCompshopping_center = shopping_center:addSprite()
    spriteCompshopping_center.texture_id = 'pokemon_sheet'
    spriteCompshopping_center.useTextureRect = true
    spriteCompshopping_center.textureRect = IntRect.new(148, 528, 144, 144)
end

function Buildings.Apartment1.new(position)
    local apartment_1 = entityManager:createEntity()
    apartment_1.name = 'apartment_1_' .. apartment_1.id
    local transformCompapartment_1 = apartment_1:addTransform()
    if position ~= nil then
        transformCompapartment_1.position = position
    end
    transformCompapartment_1.scale = Vector2.new(1, 1)
    transformCompapartment_1.rotation = 0

    local spriteCompapartment_1 = apartment_1:addSprite()
    spriteCompapartment_1.texture_id = 'pokemon_sheet'
    spriteCompapartment_1.useTextureRect = true
    spriteCompapartment_1.textureRect = IntRect.new(352, 400, 64, 128)
end

function Buildings.Apartment2.new(position)
    local apartment_2 = entityManager:createEntity()
    apartment_2.name = 'apartment_2_' .. apartment_2.id
    local transformCompapartment_2 = apartment_2:addTransform()
    if position ~= nil then
        transformCompapartment_2.position = position
    end
    transformCompapartment_2.scale = Vector2.new(1, 1)
    transformCompapartment_2.rotation = 0

    local apartment_2_top = entityManager:createEntityOnParent(apartment_2)
    apartment_2_top.name = 'apartment_2_' .. apartment_2.id .. '_top_' .. apartment_2_top.id
    local transformCompapartment_2_top = apartment_2_top:addTransform()
    transformCompapartment_2_top.position = Vector3.new(0, 0, 2)
    transformCompapartment_2_top.scale = Vector2.new(1, 1)
    transformCompapartment_2_top.rotation = 0

    local spriteCompapartment_2_top = apartment_2_top:addSprite()
    spriteCompapartment_2_top.texture_id = 'pokemon_sheet'
    spriteCompapartment_2_top.useTextureRect = true
    spriteCompapartment_2_top.textureRect = IntRect.new(720, 192, 64, 84)

    local apartment_2_bottom = entityManager:createEntityOnParent(apartment_2)
    apartment_2_bottom.name = 'apartment_2_' .. apartment_2.id .. '_bottom_' .. apartment_2_top.id
    local transformCompapartment_2_bottom = apartment_2_bottom:addTransform()
    transformCompapartment_2_bottom.position = Vector3.new(0, 84, 0)
    transformCompapartment_2_bottom.scale = Vector2.new(1, 1)
    transformCompapartment_2_bottom.rotation = 0

    local spriteCompapartment_2_bottom = apartment_2_bottom:addSprite()
    spriteCompapartment_2_bottom.texture_id = 'pokemon_sheet'
    spriteCompapartment_2_bottom.useTextureRect = true
    spriteCompapartment_2_bottom.textureRect = IntRect.new(720, 272, 64, 48)

    return apartment_2, apartment_2_top, apartment_2_bottom
end

function Buildings.Apartment3.new(position)
    local apartment_3 = entityManager:createEntity()
    apartment_3.name = 'apartment_3_' .. apartment_3.id
    local transformCompapartment_3 = apartment_3:addTransform()
    if position ~= nil then
        transformCompapartment_3.position = position
    end
    transformCompapartment_3.scale = Vector2.new(1, 1)
    transformCompapartment_3.rotation = 0

    local spriteCompapartment_3 = apartment_3:addSprite()
    spriteCompapartment_3.texture_id = 'pokemon_sheet'
    spriteCompapartment_3.useTextureRect = true
    spriteCompapartment_3.textureRect = IntRect.new(720, 64, 80, 128)

    return apartment_3
end

function Buildings.Apartment4.new(position)
    local apartment_4 = entityManager:createEntity()
    apartment_4.name = 'apartment_4_' .. apartment_4.id
    local transformCompapartment_4 = apartment_4:addTransform()
    if position ~= nil then
        transformCompapartment_4.position = position
    end
    transformCompapartment_4.scale = Vector2.new(1, 1)
    transformCompapartment_4.rotation = 0

    local apartment_4_top = entityManager:createEntityOnParent(apartment_4)
    apartment_4_top.name = "apartment_4_" .. apartment_4.id .. "_top_" .. apartment_4_top.id 
    local transformCompapartment_4_top = apartment_4_top:addTransform()
    transformCompapartment_4_top.position = Vector3.new(0, 0, 2)
    transformCompapartment_4_top.scale = Vector2.new(1, 1)
    transformCompapartment_4_top.rotation = 0

    local spriteCompapartment_4_top = apartment_4_top:addSprite()
    spriteCompapartment_4_top.texture_id = 'pokemon_sheet'
    spriteCompapartment_4_top.useTextureRect = true
    spriteCompapartment_4_top.textureRect = IntRect.new(480, 464, 80, 32)

    local apartment_4_bottom = entityManager:createEntityOnParent(apartment_4)
    apartment_4_bottom.name = 'apartment_4_' .. apartment_4.id .. '_bottom_' .. apartment_4_bottom.id
    local transformCompapartment_4_bottom = apartment_4_bottom:addTransform()
    transformCompapartment_4_bottom.position = Vector3.new(0, 30, 0)
    transformCompapartment_4_bottom.scale = Vector2.new(1, 1)
    transformCompapartment_4_bottom.rotation = 0

    local spriteCompapartment_4_bottom = apartment_4_bottom:addSprite()
    spriteCompapartment_4_bottom.texture_id = 'pokemon_sheet'
    spriteCompapartment_4_bottom.useTextureRect = true
    spriteCompapartment_4_bottom.textureRect = IntRect.new(480, 496, 80, 176)

    return apartment_4, apartment_4_top, apartment_4_bottom
end


function Buildings.Apartment5.new(position)
    local apartment_5 = entityManager:createEntity()
    apartment_5.name = 'apartment_5_' .. apartment_5.id
    local transformCompapartment_5 = apartment_5:addTransform()
    if position ~= nil then
        transformCompapartment_5.position = position
    end
    transformCompapartment_5.scale = Vector2.new(1, 1)
    transformCompapartment_5.rotation = 0

    local apartment_5_top = entityManager:createEntityOnParent(apartment_5)
    apartment_5_top.name = 'apartment_5_' .. apartment_5.id ..'_top' .. apartment_5_top.id
    local transformCompapartment_5_top = apartment_5_top:addTransform()
    transformCompapartment_5_top.position = Vector3.new(0, 0, 2)
    transformCompapartment_5_top.scale = Vector2.new(1, 1)
    transformCompapartment_5_top.rotation = 0

    local spriteCompapartment_5_top = apartment_5_top:addSprite()
    spriteCompapartment_5_top.texture_id = 'pokemon_sheet'
    spriteCompapartment_5_top.useTextureRect = true
    spriteCompapartment_5_top.textureRect = IntRect.new(272, 416, 80, 64)

    local apartment_5_bottom = entityManager:createEntityOnParent(apartment_5)
    apartment_5_bottom.name = 'apartment_5_' .. apartment_5.id .. '_bottom' .. apartment_5_bottom.id
    local transformCompapartment_5_bottom = apartment_5_bottom:addTransform()
    transformCompapartment_5_bottom.position = Vector3.new(0, 64, 0)
    transformCompapartment_5_bottom.scale = Vector2.new(1, 1)
    transformCompapartment_5_bottom.rotation = 0

    local spriteCompapartment_5_bottom = apartment_5_bottom:addSprite()
    spriteCompapartment_5_bottom.texture_id = 'pokemon_sheet'
    spriteCompapartment_5_bottom.useTextureRect = true
    spriteCompapartment_5_bottom.textureRect = IntRect.new(272, 480, 80, 48)

    return apartment_5, apartment_5_top, apartment_5_bottom
end

function Buildings.Station.new(position)
    local station = entityManager:createEntity()
    station.name = 'station_' .. station.id
    local transformCompstation = station:addTransform()
    if position ~= nil then
        transformCompstation.position = position
    end
    transformCompstation.scale = Vector2.new(1, 1)
    transformCompstation.rotation = 0

    local spriteCompstation = station:addSprite()
    spriteCompstation.texture_id = 'pokemon_sheet'
    spriteCompstation.useTextureRect = true
    spriteCompstation.textureRect = IntRect.new(0, 480, 144, 192)

    return station
end

function Buildings.School.new(position)
    local school = entityManager:createEntity()
    school.name = 'school_' .. school.id
    local transformCompschool = school:addTransform()
    transformCompschool.position = Vector3.new(770, 800, 0)
    if position ~= nil then
        transformCompschool.position = position
    end
    transformCompschool.scale = Vector2.new(1, 1)
    transformCompschool.rotation = 0

    local school_top = entityManager:createEntityOnParent(school)
    school_top.name = 'school_' .. school.id .. '_top_' .. school_top.id
    local transformCompschool_top = school_top:addTransform()
    transformCompschool_top.position = Vector3.new(0, 0, 2)
    transformCompschool_top.scale = Vector2.new(1, 1)
    transformCompschool_top.rotation = 0

    local spriteCompschool_top = school_top:addSprite()
    spriteCompschool_top.texture_id = 'pokemon_sheet'
    spriteCompschool_top.useTextureRect = true
    spriteCompschool_top.textureRect = IntRect.new(432, 226, 144, 32)

    local school_bottom = entityManager:createEntityOnParent(school)
    school_bottom.name = 'school_' .. school.id .. '_bottom_' .. school_bottom.id
    local transformCompschool_bottom = school_bottom:addTransform()
    transformCompschool_bottom.position = Vector3.new(0, 32, 0)
    transformCompschool_bottom.scale = Vector2.new(1, 1)
    transformCompschool_bottom.rotation = 0

    local spriteCompschool_bottom = school_bottom:addSprite()
    spriteCompschool_bottom.texture_id = 'pokemon_sheet'
    spriteCompschool_bottom.useTextureRect = true
    spriteCompschool_bottom.textureRect = IntRect.new(432, 256, 144, 64)

    return school, school_top, school_bottom
end

function Buildings.Gym.new(position)
    local gym = entityManager:createEntity()
    gym.name = 'gym_' .. gym.id
    local transformCompgym = gym:addTransform()
    if position ~= nil then
        transformCompgym.position = position
    end
    transformCompgym.scale = Vector2.new(1, 1)
    transformCompgym.rotation = 0

    local spriteCompgym = gym:addSprite()
    spriteCompgym.texture_id = 'pokemon_sheet'
    spriteCompgym.useTextureRect = true
    spriteCompgym.textureRect = IntRect.new(304, 544, 160, 128)

    return gym
end

function Buildings.SplitTemplate.new(position)
    local temp = entityManager:createEntity()
    local tempTransform = temp:addTransform()

    local temp_top = entityManager:createEntityOnParent(temp)
    local temp_top_transform = temp_top:addTransform()
    local temp_top_sprite = temp_top:addSprite()

    local temp_bottom = entityManager:createEntityOnParent(temp)
    local temp_bottom_transform = temp_bottom:addTransform()
    local temp_bottom_sprite = temp_bottom:addSprite()

    return temp, temp_top, temp_bottom
end

function Buildings.Template.new(position)
    local temp = entityManager:createEntity()
    local tempTransform = temp:addTransform()
    local tempSprite = temp:addSprite()

    return temp
end