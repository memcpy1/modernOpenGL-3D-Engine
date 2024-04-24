#version 330


struct LightMaterial {
    
	vec3 AmbienceColor;
    vec3 DiffuseColor;
    vec3 SpecularColor;
    float ShineRadius;
}; 

struct PointLight
{
	vec3 position;

	float Constant;
	float Linear;
	float Quadratic;
	
	sampler2D Ambience;
	sampler2D Diffuse;
	sampler2D Specular;
};

struct DirectionalLight
{
	vec3 direction;	
	
	sampler2D Ambience;
	sampler2D Diffuse;
	sampler2D Specular;	
};

struct SpotLight
{
	
	vec3 position;
	vec3 direction;

	float CutOff;
	float OuterCutOff;

	float Constant;
	float Linear;
	float Quadratic;

	sampler2D Ambience;
	sampler2D Diffuse;
	sampler2D Specular;
};

struct Light 
{
	
	vec3 Color;

    vec3 AmbientIntensity;
    vec3 DiffuseIntensity;
    vec3 SpecularIntensity;
};


#define NR_POINT_LIGHTS 4  


//output
out vec4 color;

in vec3 oNormal;
in vec3 oFragmentPosition;
in vec2 oTextureCoordinates;

uniform vec3 ViewPosition;

uniform DirectionalLight dir;
uniform PointLight point[NR_POINT_LIGHTS];
uniform SpotLight spotlight;

uniform LightMaterial material;
uniform Light light;

uniform sampler2D texture_diffuse1;
uniform sampler2D texture_specular1;



vec3 GetDirectionalLight(DirectionalLight dirlight, vec3 normal, vec3 viewpos)
{
	vec3 LightDir = normalize(-dirlight.direction);  

	vec3 Ambience = light.AmbientIntensity * vec3(texture(dirlight.Ambience, oTextureCoordinates));
	
	vec3 Normal = normalize(normal);
	float Diff = max(dot(Normal, LightDir), 0.0);
	vec3 Diffuse =  light.DiffuseIntensity * Diff * vec3(texture(dirlight.Diffuse, oTextureCoordinates));

	vec3 ViewDirection = normalize(viewpos - oFragmentPosition);
	vec3 ReflectDir = reflect(-LightDir, Normal);  
	float spec = pow(max(dot(ViewDirection, ReflectDir), 0.0), material.ShineRadius);
	vec3 Specular = light.SpecularIntensity * spec * vec3(texture(dirlight.Specular, oTextureCoordinates));

	return (Ambience + Diffuse + Specular);
}

vec3 GetLightFromPoint(PointLight point, vec3 normal, vec3 fragpos, vec3 viewpos)
{
	vec3 LightDir = normalize(point.position - fragpos);  
	
	vec3 Ambience = light.AmbientIntensity * vec3(texture(texture_diffuse1, oTextureCoordinates));

	
	vec3 Normal = normalize(normal);
	float Diff = max(dot(Normal, LightDir), 0.0);
	vec3 Diffuse =  light.DiffuseIntensity * Diff * vec3(texture(texture_diffuse1, oTextureCoordinates));

	
	vec3 ViewDirection = normalize(viewpos - fragpos);
	vec3 ReflectDir = reflect(-LightDir, Normal);  
	float spec = pow(max(dot(ViewDirection, ReflectDir), 0.0), material.ShineRadius);
	vec3 Specular = light.SpecularIntensity * spec * vec3(texture(texture_specular1, oTextureCoordinates));  
	

	float Distance = length(point.position - fragpos);
	float Attenuation = 1.0 / (point.Constant + point.Linear * Distance + point.Quadratic * pow(Distance, 2));

   
	return (Ambience * Attenuation + Diffuse * Attenuation + Specular * Attenuation);
}

vec3 GetLightFromPointMat(PointLight point, vec3 normal, vec3 fragpos, vec3 viewpos)
{
	vec3 LightDir = normalize(point.position - fragpos);  
	
	vec3 Ambience = light.AmbientIntensity * material.AmbienceColor;

	
	vec3 Normal = normalize(normal);
	float Diff = max(dot(Normal, LightDir), 0.0);
	vec3 Diffuse =  light.DiffuseIntensity * Diff * material.DiffuseColor;

	
	vec3 ViewDirection = normalize(viewpos - fragpos);
	vec3 ReflectDir = reflect(-LightDir, Normal);  
	float spec = pow(max(dot(ViewDirection, ReflectDir), 0.0), material.ShineRadius);
	vec3 Specular = light.SpecularIntensity * spec * material.SpecularColor;  
	

	float Distance = length(point.position - fragpos);
	float Attenuation = 1.0 / (point.Constant + point.Linear * Distance + point.Quadratic * pow(Distance, 2));

   
	return (Ambience * Attenuation + Diffuse * Attenuation + Specular * Attenuation);
}

vec3 GetSpotLight(SpotLight spot, vec3 normal, vec3 fragpos, vec3 viewpos)
{
	vec3 LightDir = normalize(spot.position - fragpos);  
	
	

	
	vec3 Ambience = 0.1 * material.AmbienceColor;

	
	vec3 Normal = normalize(normal);
	float Diff = max(dot(Normal, LightDir), 0.0);
	vec3 Diffuse =  light.DiffuseIntensity * Diff * material.DiffuseColor;

	
	vec3 ViewDirection = normalize(viewpos - fragpos);
	vec3 ReflectDir = reflect(-LightDir, Normal);  
	float spec = pow(max(dot(ViewDirection, ReflectDir), 0.0), material.ShineRadius);
	vec3 Specular = light.SpecularIntensity * spec * material.SpecularColor;  

	float Theta = dot(LightDir, normalize(-spot.direction));
	float Epsilon = (spot.CutOff - spot.OuterCutOff);
	float Intensity = clamp((Theta - spot.OuterCutOff) / Epsilon, 0.0, 1.0);
	
	Diffuse  *= Intensity;
	Specular *= Intensity;

	float Distance = length(spot.position - fragpos);
	float Attenuation = 1.0 / (spot.Constant + spot.Linear * Distance + spot.Quadratic * pow(Distance, 2));

   
	return (Ambience + Diffuse * Attenuation + Specular * Attenuation);
}


void main()
{
	vec3 Output = vec3(0);


	Output = GetLightFromPoint(point[0], oNormal, oFragmentPosition, ViewPosition);
	//Output = GetSpotLight(spotlight, oNormal, oFragmentPosition, ViewPosition);

    color = vec4(Output, 1.0);
}
		
