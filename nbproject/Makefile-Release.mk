#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/CLIENTE.o \
	${OBJECTDIR}/COMENTARIO.o \
	${OBJECTDIR}/COMPRA.o \
	${OBJECTDIR}/CONTROLADOR.o \
	${OBJECTDIR}/DataDireccion.o \
	${OBJECTDIR}/DataProd.o \
	${OBJECTDIR}/DataProducto.o \
	${OBJECTDIR}/FABRICA.o \
	${OBJECTDIR}/ICollection/Integer.o \
	${OBJECTDIR}/ICollection/String.o \
	${OBJECTDIR}/ICollection/collections/List.o \
	${OBJECTDIR}/ICollection/collections/ListIterator.o \
	${OBJECTDIR}/ICollection/collections/ListNode.o \
	${OBJECTDIR}/ICollection/collections/OrderedDictionary.o \
	${OBJECTDIR}/ICollection/collections/OrderedDictionaryEntry.o \
	${OBJECTDIR}/ICollection/interfaces/ICollectible.o \
	${OBJECTDIR}/ICollection/interfaces/ICollection.o \
	${OBJECTDIR}/ICollection/interfaces/IDictionary.o \
	${OBJECTDIR}/ICollection/interfaces/IIterator.o \
	${OBJECTDIR}/ICollection/interfaces/IKey.o \
	${OBJECTDIR}/ICollection/interfaces/OrderedKey.o \
	${OBJECTDIR}/PRODUCTO.o \
	${OBJECTDIR}/PROMOCION.o \
	${OBJECTDIR}/USUARIO.o \
	${OBJECTDIR}/VENDEDOR.o \
	${OBJECTDIR}/compra_producto.o \
	${OBJECTDIR}/date.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/promocion_producto.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/utecmercadosuelto

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/utecmercadosuelto: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/utecmercadosuelto ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/CLIENTE.o: CLIENTE.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CLIENTE.o CLIENTE.cpp

${OBJECTDIR}/COMENTARIO.o: COMENTARIO.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/COMENTARIO.o COMENTARIO.cpp

${OBJECTDIR}/COMPRA.o: COMPRA.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/COMPRA.o COMPRA.cpp

${OBJECTDIR}/CONTROLADOR.o: CONTROLADOR.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CONTROLADOR.o CONTROLADOR.cpp

${OBJECTDIR}/DataDireccion.o: DataDireccion.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataDireccion.o DataDireccion.cpp

${OBJECTDIR}/DataProd.o: DataProd.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataProd.o DataProd.cpp

${OBJECTDIR}/DataProducto.o: DataProducto.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DataProducto.o DataProducto.cpp

${OBJECTDIR}/FABRICA.o: FABRICA.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FABRICA.o FABRICA.cpp

${OBJECTDIR}/ICollection/Integer.o: ICollection/Integer.cpp
	${MKDIR} -p ${OBJECTDIR}/ICollection
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ICollection/Integer.o ICollection/Integer.cpp

${OBJECTDIR}/ICollection/String.o: ICollection/String.cpp
	${MKDIR} -p ${OBJECTDIR}/ICollection
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ICollection/String.o ICollection/String.cpp

${OBJECTDIR}/ICollection/collections/List.o: ICollection/collections/List.cpp
	${MKDIR} -p ${OBJECTDIR}/ICollection/collections
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ICollection/collections/List.o ICollection/collections/List.cpp

${OBJECTDIR}/ICollection/collections/ListIterator.o: ICollection/collections/ListIterator.cpp
	${MKDIR} -p ${OBJECTDIR}/ICollection/collections
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ICollection/collections/ListIterator.o ICollection/collections/ListIterator.cpp

${OBJECTDIR}/ICollection/collections/ListNode.o: ICollection/collections/ListNode.cpp
	${MKDIR} -p ${OBJECTDIR}/ICollection/collections
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ICollection/collections/ListNode.o ICollection/collections/ListNode.cpp

${OBJECTDIR}/ICollection/collections/OrderedDictionary.o: ICollection/collections/OrderedDictionary.cpp
	${MKDIR} -p ${OBJECTDIR}/ICollection/collections
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ICollection/collections/OrderedDictionary.o ICollection/collections/OrderedDictionary.cpp

${OBJECTDIR}/ICollection/collections/OrderedDictionaryEntry.o: ICollection/collections/OrderedDictionaryEntry.cpp
	${MKDIR} -p ${OBJECTDIR}/ICollection/collections
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ICollection/collections/OrderedDictionaryEntry.o ICollection/collections/OrderedDictionaryEntry.cpp

${OBJECTDIR}/ICollection/interfaces/ICollectible.o: ICollection/interfaces/ICollectible.cpp
	${MKDIR} -p ${OBJECTDIR}/ICollection/interfaces
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ICollection/interfaces/ICollectible.o ICollection/interfaces/ICollectible.cpp

${OBJECTDIR}/ICollection/interfaces/ICollection.o: ICollection/interfaces/ICollection.cpp
	${MKDIR} -p ${OBJECTDIR}/ICollection/interfaces
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ICollection/interfaces/ICollection.o ICollection/interfaces/ICollection.cpp

${OBJECTDIR}/ICollection/interfaces/IDictionary.o: ICollection/interfaces/IDictionary.cpp
	${MKDIR} -p ${OBJECTDIR}/ICollection/interfaces
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ICollection/interfaces/IDictionary.o ICollection/interfaces/IDictionary.cpp

${OBJECTDIR}/ICollection/interfaces/IIterator.o: ICollection/interfaces/IIterator.cpp
	${MKDIR} -p ${OBJECTDIR}/ICollection/interfaces
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ICollection/interfaces/IIterator.o ICollection/interfaces/IIterator.cpp

${OBJECTDIR}/ICollection/interfaces/IKey.o: ICollection/interfaces/IKey.cpp
	${MKDIR} -p ${OBJECTDIR}/ICollection/interfaces
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ICollection/interfaces/IKey.o ICollection/interfaces/IKey.cpp

${OBJECTDIR}/ICollection/interfaces/OrderedKey.o: ICollection/interfaces/OrderedKey.cpp
	${MKDIR} -p ${OBJECTDIR}/ICollection/interfaces
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ICollection/interfaces/OrderedKey.o ICollection/interfaces/OrderedKey.cpp

${OBJECTDIR}/PRODUCTO.o: PRODUCTO.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PRODUCTO.o PRODUCTO.cpp

${OBJECTDIR}/PROMOCION.o: PROMOCION.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PROMOCION.o PROMOCION.cpp

${OBJECTDIR}/USUARIO.o: USUARIO.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/USUARIO.o USUARIO.cpp

${OBJECTDIR}/VENDEDOR.o: VENDEDOR.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VENDEDOR.o VENDEDOR.cpp

${OBJECTDIR}/compra_producto.o: compra_producto.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/compra_producto.o compra_producto.cpp

${OBJECTDIR}/date.o: date.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/date.o date.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/promocion_producto.o: promocion_producto.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/promocion_producto.o promocion_producto.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
